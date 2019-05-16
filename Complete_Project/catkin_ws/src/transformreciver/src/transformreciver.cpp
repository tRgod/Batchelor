//
// Created by thor on 4/29/19.
//



#include <ros/ros.h>
#include <tf/transform_listener.h>
#include <tf/tf.h>
#include <geometry_msgs/PoseStamped.h>


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

    double calculateRotation(double &currentOrientation){
        double rotation;
        if ( currentOrientation > M_PI/2 && previousOrientation < -M_PI/2){
            rotation =currentOrientation - previousOrientation - 2*M_PI;
            previousOrientation = currentOrientation;
            return rotation;
        }
        if( currentOrientation < -M_PI/2 && previousOrientation > M_PI/2 ){
            rotation = currentOrientation - previousOrientation + 2 * M_PI;
            previousOrientation = currentOrientation;
            return rotation;
        }
        rotation = currentOrientation-previousOrientation;
        previousOrientation = currentOrientation;
        return rotation;
    }

    void publishTranslation() {
        geometry_msgs::PoseStamped poseStamped;
        tf::StampedTransform transform;
        try {
            ros::Time now = ros::Time::now();
            listener.waitForTransform("velodyneVPL", "world", now, ros::Duration(1));
            listener.lookupTransform("velodyneVPL", "world", now, transform);
        }
        catch (tf::TransformException &ex) {
            ROS_ERROR("%s", ex.what());

        }
        if (previousTime != transform.stamp_) {

            /*
            poseStamped.header.stamp = transform.stamp_;
            poseStamped.header.frame_id = transform.frame_id_;
            poseStamped.pose.position.x = transform.getOrigin().getX();
            poseStamped.pose.position.y = transform.getOrigin().getY();
            poseStamped.pose.position.z = transform.getOrigin().getZ();
            poseStamped.pose.orientation.x = transform.getRotation().x();
            poseStamped.pose.orientation.y = transform.getRotation().y();
            poseStamped.pose.orientation.z = transform.getRotation().z();
            poseStamped.pose.orientation.w = transform.getRotation().w();*/

            double deltaX = transform.getOrigin().getX()-previousTransform.getOrigin().getX();
            double deltaY = transform.getOrigin().getY()-previousTransform.getOrigin().getY();
            double translation = sqrt(pow(deltaX,2)+pow(deltaY,2));
            double orientation = atan2(deltaY, deltaX);
            double rotation = calculateRotation(orientation);
            //ROS_INFO("x1[%f] x0[%f] y1[%f] y0[%f] translation [%f] rotation [%f]",transform.getOrigin().getX(),  previousTransform.getOrigin().getX(),transform.getOrigin().getY(),previousTransform.getOrigin().getY(), translation, rotation);
            ROS_INFO("x [%lf", double(transform.getOrigin().getX()));
            transform_pub.publish(poseStamped);
            previousTransform = transform;
            previousTime = transform.stamp_;
        }
    }

private:
    ros::NodeHandle node;
    ros::Publisher transform_pub = node.advertise<geometry_msgs::PoseStamped>("transform_pose", 10);
    ros::Time previousTime = ros::Time::now();
    tf::StampedTransform previousTransform;
    tf::TransformListener listener;
    double previousOrientation;
};

int main(int argc,char** argv)
{
    ros::init(argc,argv,"Transform_listener");

    TransformReceiver transformReceiver;

    ros:: Rate rate(5);

    while(ros::ok())
    {
        transformReceiver.publishTranslation();
        rate.sleep();

    }
    return 0;
}

