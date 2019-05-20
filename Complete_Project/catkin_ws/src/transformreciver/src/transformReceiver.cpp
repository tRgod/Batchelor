//
// Created by gilberg96 on 5/17/19.
//
#include <ros/ros.h>
#include <geometry_msgs/TransformStamped.h>
#include <tf2/utils.h>
#include <tf2_ros/transform_listener.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.h>
#include <tf2_msgs/TFMessage.h>
#include <geometry_msgs/TwistStamped.h>

class TransformReceiver{
public:
    TransformReceiver():tfListener(tfBuffer){
        geometry_msgs::TransformStamped transformStamped;
        try {
            transformStamped = tfBuffer.lookupTransform("velodyneVPL", "world", ros::Time::now(), ros::Duration(10));
        }
        catch (tf2::TransformException &ex){
            ROS_WARN("%s", ex.what());
        }
        tf2::fromMsg(transformStamped,previousTransform);

    }
    void publishTransform(){
        geometry_msgs::TransformStamped transformStamped;
        geometry_msgs::TwistStamped twistStamped;
        try {
            transformStamped = tfBuffer.lookupTransform("velodyneVPL", "world", ros::Time::now(), ros::Duration(10));
        }
        catch (tf2::TransformException &ex){
            ROS_WARN("%s", ex.what());
        }
        tf2::Stamped<tf2::Transform> transform;
        tf2::fromMsg(transformStamped,transform);

        twistStamped.header.stamp = transform.stamp_;
        twistStamped.twist.angular.z = tf2::getYaw(transform.inverseTimes(previousTransform).getRotation());
        twistStamped.twist.linear.x = sqrt(pow(transform.getOrigin().x()-previousTransform.getOrigin().x(),2)+pow(transform.getOrigin().y()-previousTransform.getOrigin().y(),2));
        twist_pub.publish(twistStamped);
        previousTransform = transform;

    }

private:
    ros::NodeHandle n;
    tf2_ros::Buffer tfBuffer;
    tf2_ros::TransformListener tfListener;
    tf2::Stamped<tf2::Transform> previousTransform;
    ros::Publisher twist_pub = n.advertise<geometry_msgs::TwistStamped>("twist_stamped", 10);

};

int main(int argc, char** argv){
    ros::init(argc, argv, "transform_receiver");
    TransformReceiver transformReceiver;

    ros::Rate rate(100);
    while(ros::ok()){
        transformReceiver.publishTransform();
        rate.sleep();
    }
    return 0;

}
