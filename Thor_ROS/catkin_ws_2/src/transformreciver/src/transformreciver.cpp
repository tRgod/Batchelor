//
// Created by thor on 4/29/19.
//



#include <ros/ros.h>
#include <tf/transform_listener.h>
#include <geometry_msgs/PoseStamped.h>

int main(int argc,char** argv)
{
    ros::init(argc,argv,"Transform_listner");
    ros::NodeHandle node;
    ros::Publisher transform_pub=node.advertise<geometry_msgs::PoseStamped>("transform_pose",10);
    tf::TransformListener listner;
    ros:: Rate rate(5.0);
    while(node.ok())
    {
        tf::StampedTransform transform;
        try
        {
            listner.lookupTransform("velodyneVPL", "world", ros::Time(0),transform);
        }
        catch (tf::TransformException &ex)
        {
            ROS_ERROR("%s",ex.what());

        }
        geometry_msgs::PoseStamped trans_pose;
        trans_pose.header.frame_id = "/Velodyne";
        trans_pose.header.stamp = ros::Time::now();
        trans_pose.position.x=transform.getOrigin().x();
        trans_pose.position.y=transform.getOrigin().y();
        trans_pose.position.z=transform.getOrigin().z();
        trans_pose.orientation.x=transform.getRotation().getX();
        trans_pose.orientation.y=transform.getRotation().getY();
        trans_pose.orientation.z=transform.getRotation().getZ();
        trans_pose.orientation.w=transform.getRotation().getW();
        transform_pub.publish(trans_pose);
        rate.sleep();

    }
    return 0;
}


