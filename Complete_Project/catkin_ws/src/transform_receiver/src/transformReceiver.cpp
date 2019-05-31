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

#include <chrono>
#include <random>

class TransformReceiver{
public:
    TransformReceiver():tfListener(tfBuffer), transform_sub(n.subscribe("/stamped_transform", 10, &TransformReceiver::transformStampedCallback, this)){
        /*geometry_msgs::TransformStamped transformStamped;

        ros::Time begin = ros::Time(0.0001);
        try {
            transformStamped = tfBuffer.lookupTransform("velodyneVPL", "world", begin, ros::Duration(60));
        }
        catch (tf2::TransformException &ex){
            ROS_WARN("%s", ex.what());
        }
        tf2::fromMsg(transformStamped,previousTransform);*/

    }

    void publishTransform(ros::Time &now){
        geometry_msgs::TransformStamped transformStamped;
        geometry_msgs::TwistStamped twistStamped;
        try {
            transformStamped = tfBuffer.lookupTransform("velodyneVPL", "world", now, ros::Duration(10));
        }
        catch (tf2::TransformException &ex){
            ROS_WARN("%s", ex.what());
        }
        tf2::Stamped<tf2::Transform> transform;
        tf2::fromMsg(transformStamped,transform);
        std::cout << transform.stamp_.toSec() << " x: " << transform.getOrigin().x() << " y: " << transform.getOrigin().y() << std::endl;

        twistStamped.header.stamp = transform.stamp_;
        twistStamped.twist.angular.z = tf2::getYaw(transform.inverseTimes(previousTransform).getRotation());
        twistStamped.twist.linear.x = sqrt(pow(transform.getOrigin().x()-previousTransform.getOrigin().x(),2)+pow(transform.getOrigin().y()-previousTransform.getOrigin().y(),2))+d(gen);
        twist_pub.publish(twistStamped);
        previousTransform = transform;

    }

    void transformStampedCallback(const geometry_msgs::TransformStamped::ConstPtr &msg){
        tf2::Stamped<tf2::Transform> transform;
        geometry_msgs::TwistStamped twistStamped;

        /*try {
            transformStamped = tfBuffer.lookupTransform("velodyneVPL", "world", msg->header.stamp, ros::Duration(10));
        }
        catch (tf2::TransformException &ex){
            ROS_WARN("%s", ex.what());
        }
        tf2::Stamped<tf2::Transform> transform;
        tf2::fromMsg(transformStamped,transform);
        std::cout << transform.stamp_.toSec() << " x: " << transform.getOrigin().x() << " y: " << transform.getOrigin().y() << std::endl;

        twistStamped.header.stamp = transform.stamp_;
        twistStamped.twist.angular.z = tf2::getYaw(transform.inverseTimes(previousTransform).getRotation());
        twistStamped.twist.linear.x = sqrt(pow(transform.getOrigin().x()-previousTransform.getOrigin().x(),2)+pow(transform.getOrigin().y()-previousTransform.getOrigin().y(),2));
        twist_pub.publish(twistStamped);
        previousTransform = transform;*/
        if(msg->header.seq == 0){
            tf2::fromMsg(*msg,previousTransform);
        }
        else{
            tf2::fromMsg(*msg,transform);
            twistStamped.header.stamp = transform.stamp_;
            twistStamped.twist.angular.z = tf2::getYaw(transform.inverseTimes(previousTransform).getRotation())+da(gen);
            twistStamped.twist.linear.x = sqrt(pow(transform.getOrigin().x()-previousTransform.getOrigin().x(),2)+pow(transform.getOrigin().y()-previousTransform.getOrigin().y(),2))+d(gen);
            twist_pub.publish(twistStamped);
            previousTransform = transform;
        }
    }

private:
    ros::NodeHandle n;
    tf2_ros::Buffer tfBuffer;
    tf2_ros::TransformListener tfListener;
    tf2::Stamped<tf2::Transform> previousTransform;
    ros::Publisher twist_pub = n.advertise<geometry_msgs::TwistStamped>("twist_stamped", 10);
    ros::Subscriber transform_sub;

    std::random_device rd{};
    std::mt19937 gen{rd()};
    std::normal_distribution<double> d{0.0,0.05};
    std::normal_distribution<double> da{0.0, 0.005};
};

int main(int argc, char** argv){
    ros::init(argc, argv, "transform_receiver");

    TransformReceiver transformReceiver;

    ros::spin();
    return 0;

}
