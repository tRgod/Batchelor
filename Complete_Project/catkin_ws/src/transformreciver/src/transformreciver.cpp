//
// Created by thor on 4/29/19.
//



#include <ros/ros.h>
#include <tf/transform_listener.h>
#include <tf/tf.h>
#include <geometry_msgs/PoseStamped.h>

int main(int argc,char** argv)
{
    ros::init(argc,argv,"Transform_listner");
    ros::NodeHandle node;
    ros::Publisher transform_pub=node.advertise<geometry_msgs::PoseStamped>("transform_pose",10);
    tf::TransformListener listner;
    ros::Time previousTime = ros::Time::now();
    ros:: Rate rate(5);

    while(node.ok())
    {
        geometry_msgs::PoseStamped poseStamped;
        tf::StampedTransform transform;
        try
        {
            ros::Time now = ros::Time::now();
            listner.waitForTransform("velodyneVPL", "world", now, ros::Duration(1));
            listner.lookupTransform("velodyneVPL", "world", now, transform);

        }
        catch (tf::TransformException &ex)
        {
            ROS_ERROR("%s",ex.what());

        }
        if (previousTime != transform.stamp_){
            poseStamped.header.stamp = transform.stamp_;
            poseStamped.header.frame_id = transform.frame_id_;
            poseStamped.pose.position.x = transform.getOrigin().getX();
            poseStamped.pose.position.y = transform.getOrigin().getY();
            poseStamped.pose.position.z = transform.getOrigin().getZ();
            poseStamped.pose.orientation.x = transform.getRotation().x();
            poseStamped.pose.orientation.y = transform.getRotation().y();
            poseStamped.pose.orientation.z = transform.getRotation().z();
            poseStamped.pose.orientation.w = transform.getRotation().w();

            transform_pub.publish(poseStamped);
            previousTime = transform.stamp_;
        }

        rate.sleep();

    }
    return 0;
}

