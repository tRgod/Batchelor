//
// Created by thor on 4/29/19.
//



#include <ros/ros.h>
#include <tf/transform_listener.h>
#include <tf/tf.h>
#include <geometry_msgs/TwistStamped.h>

struct Pose{
    double changeDist;
    double changeOri;
};

class TransformReceiver{
public:
    TransformReceiver(){
        try {
            listener.waitForTransform("velodyneVPL", "world", ros::Time(0), ros::Duration(60));
            listener.lookupTransform("velodyneVPL", "world", ros::Time(0), previousTransform);
            previousOrientation = atan2(previousTransform.getOrigin().getY(), previousTransform.getOrigin().getX());
            previousTime = previousTransform.stamp_;
        }
        catch (tf::TransformException &ex) {
            ROS_ERROR("%s", ex.what());
        }
    }

    double constrainAngle(double x)
    {
        x=fmod(x+(180*M_PI)/180,(360*M_PI)/180);
        if(x<0)
            x+=(360*M_PI)/180;
        return x-(180*M_PI)/180;
    }


    Pose calculatePose(tf::StampedTransform &currentTransform){
        Pose pose;
        double prevX = previousTransform.getOrigin().getX();
        double prevY = previousTransform.getOrigin().getY();
        double currX = currentTransform.getOrigin().getX();
        double currY = currentTransform.getOrigin().getY();

        pose.changeDist = sqrt(pow(currX-prevX,2)+pow(currY-prevY,2));
        pose.changeOri =constrainAngle(atan2(currY, currX)-atan2(prevY, prevX));

        //pose.changeOri = acos((currX*prevX+currY*prevY)/(sqrt(pow(currX,2)+pow(currY,2))+sqrt(pow(prevY,2)+pow(currY,2))));
        return pose;
    }

    void publishTranslation() {
        geometry_msgs::TwistStamped twistStamped;
        tf::StampedTransform transform;
        Pose currentPose;
        try {
            ros::Time now = ros::Time::now();
            listener.waitForTransform("velodyneVPL", "world", now, ros::Duration(1));
            listener.lookupTransform("velodyneVPL", "world", now, transform);
        }
        catch (tf::TransformException &ex) {
            ROS_ERROR("%s", ex.what());

        }
        if (previousTime != transform.stamp_) {

            currentPose = calculatePose(transform);
            twistStamped.twist.linear.x = currentPose.changeDist;
            twistStamped.twist.angular.x = currentPose.changeOri;
            ROS_INFO("atan2 [%lf]", currentPose.changeOri);
            transform_pub.publish(twistStamped);
            previousTransform = transform;
            previousTime = transform.stamp_;
            ROS_INFO("Orientation [%f]", tf::getYaw(previousTransform.getRotation()));
        }
    }

private:
    ros::NodeHandle node;
    ros::Publisher transform_pub = node.advertise<geometry_msgs::TwistStamped>("transform_pose", 10);
    ros::Time previousTime = ros::Time::now();
    tf::StampedTransform previousTransform;
    tf::TransformListener listener;
    double previousOrientation;
};

int main(int argc,char** argv)
{
    ros::init(argc,argv,"Transform_listener");

    TransformReceiver transformReceiver;

    ros:: Rate rate(10);

    while(ros::ok())
    {
        transformReceiver.publishTranslation();
        rate.sleep();

    }
    return 0;
}

