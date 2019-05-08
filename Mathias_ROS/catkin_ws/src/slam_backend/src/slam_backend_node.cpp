// ROS headers
#include "ros/ros.h"
#include "std_msgs/Float64.h"
#include <geometry_msgs/PoseStamped.h>

#include "slam_backend/TimedPose.h"

#include <gtsam/geometry/Pose2.h>

#include <gtsam/inference/Symbol.h>

#include <gtsam/nonlinear/ISAM2.h>

#include <gtsam/nonlinear/NonlinearFactorGraph.h>
#include <gtsam/nonlinear/Values.h>

#include <gtsam/nonlinear/LevenbergMarquardtOptimizer.h>

#include <gtsam/slam/PriorFactor.h>
#include <gtsam/slam/BetweenFactor.h>
#include <gtsam/sam/BearingRangeFactor.h>


class iSAM2{
public:
    iSAM2(bool simulation){

        if(simulation == 0){

        }
        else {
            timedPose_sub = n.subscribe("timed_Pose", 10, &iSAM2::timedPoseCallback, this);
            timedRangeBearing_sub = n.subscribe("timedRangeBearing", 10, &iSAM2::timedRangeBearingCallback, this);
        }
        gtsam::Pose2 pose0 = gtsam::Pose2(0,0,0);

        newFactors.push_back(gtsam::PriorFactor<gtsam::Pose2>(i,pose0, priorNoise));
        initial.insert(i,pose0);

        lastPose = pose0;

        i++;

    }
    void timedPoseCallback(const slam_backend::TimedPose::ConstPtr &msg){
        double time = msg->time;
        gtsam::Pose2 odometry(msg->dist, 0, msg->steer);

        newFactors.push_back(gtsam::BetweenFactor<gtsam::Pose2>(i-1, i, odometry, odoNoise));

        gtsam::Pose2 predictedPose = lastPose.compose(odometry);
        lastPose = predictedPose;
        initial.insert(i, predictedPose);

        i++;

    }

    void timedPoseSimCallback(const geometry_msgs::PoseStamped::ConstPtr &msg){
        double time = msg->header.stamp.toSec();
    }

    void timedRangeBearingCallback(const std_msgs::Float64::ConstPtr &msg){

    }

    void run(){
    }

private:
    ros::NodeHandle n;
    ros::Subscriber timedPose_sub;
    ros::Subscriber timedRangeBearing_sub;

    gtsam::Vector priorSigmas = gtsam::Vector3( 1, 1, M_PI);
    gtsam::Vector odoSigmas = gtsam::Vector3(0.05, 0.01, 0.2);

    const gtsam::noiseModel::Base::shared_ptr priorNoise = gtsam::noiseModel::Diagonal::Sigmas(priorSigmas);
    const gtsam::noiseModel::Base::shared_ptr odoNoise = gtsam::noiseModel::Diagonal::Sigmas(odoSigmas);

    gtsam::NonlinearFactorGraph newFactors;

    gtsam::ISAM2 isam2;

    gtsam::Values initial;

    int i = 0;

    gtsam::Pose2 lastPose;

};

int main(int argc, char** argv) {

    ros::init(argc, argv, "slam_backend");

    iSAM2 backend(1);

    ros::Rate loop_rate(10);

    while(ros::ok()){
        backend.run();
        ros::spinOnce();

        loop_rate.sleep();
    }

    return 0;
}
