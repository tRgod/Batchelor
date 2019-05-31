//
// Created by gilberg96 on 5/27/19.
//
#include <ros/ros.h>
#include <geometry_msgs/PoseStamped.h>
#include <geometry_msgs/TransformStamped.h>
#include <geometry_msgs/PointStamped.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.h>
#include <tf2/utils.h>
#include <fstream>

class DataLogger{
public:
    DataLogger(){
        groundTruth_sub = n.subscribe("stamped_transform", 10, &DataLogger::groundTruthCallback, this);
        landmark_sub = n.subscribe("landmarks", 1000, &DataLogger::landmarkCallback, this);
        odometry_sub = n.subscribe("predicted_poses", 10, &DataLogger::predictedPoseCallback, this);
        iSAM2_sub = n.subscribe("isam2_poses", 10, &DataLogger::iSAM2Callback, this);

        groundTruth.open("groundTruth.txt");
        landmarks.open("landmarks.txt");
        predictedPoses.open("predictedPoses.txt");
        iSAM2Poses.open("isam2.txt");
    }

    void groundTruthCallback(const geometry_msgs::TransformStamped::ConstPtr &msg){
        tf2::Stamped<tf2::Transform> transform;
        tf2::fromMsg(*msg, transform);
        groundTruth << msg->header.stamp.toSec() << " " << msg->transform.translation.x << " " << msg->transform.translation.y << " " << tf2::getYaw(transform.getRotation()) << std::endl;
    }

    void landmarkCallback(const geometry_msgs::PointStamped::ConstPtr &msg){
        landmarks << msg->header.stamp.toSec() << " " << msg->point.z << " " << msg->point.x << " " << msg->point.y << std::endl;
    }

    void predictedPoseCallback(const geometry_msgs::PoseStamped::ConstPtr &msg){
        predictedPoses << msg->header.stamp.toSec() << " " << msg->pose.position.x << " " << msg->pose.position.y << " " << msg->pose.orientation.z << std::endl;
    }

    void iSAM2Callback(const geometry_msgs::PoseStamped::ConstPtr &msg){
        iSAM2Poses << msg->header.stamp.toSec() << " " << msg->pose.position.x << " " << msg->pose.position.y << " " << msg->pose.orientation.z << std::endl;
    }

private:
    ros::NodeHandle n;
    ros::Subscriber groundTruth_sub;
    ros::Subscriber iSAM2_sub;
    ros::Subscriber odometry_sub;
    ros::Subscriber landmark_sub;

    std::ofstream groundTruth;
    std::ofstream landmarks;
    std::ofstream predictedPoses;
    std::ofstream iSAM2Poses;
};

int main(int argc, char** argv){
    ros::init(argc, argv,"data_logger");
    DataLogger dataLogger;

    ros::spin();
}

