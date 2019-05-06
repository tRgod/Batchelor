// ROS headers
#include "ros/ros.h"
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
    iSAM2(){
        timedPose_sub = n.subscribe("timed_Pose", 10, &iSAM2::timedPoseCallback, this);

        gtsam::Vector priorSigmas = gtsam::Vector3( 1, 1, M_PI);
        gtsam::Vector odoSigmas = gtsam::Vector3(0.05, 0.01, 0.2);

        const gtsam::noiseModel::Base::shared_ptr
        priorNoise = gtsam::noiseModel::Diagonal::Sigmas(priorSigmas),
        odoNoise = gtsam::noiseModel::Diagonal::Sigmas(odoSigmas);

        gtsam::ISAM2 isam2;

    }
    void timedPoseCallback(const slam_backend::TimedPose::ConstPtr &msg){
        double time = msg->time, distance = msg->dist, steering = msg->steer;
        lastPose = gtsam::Pose2(distance, 0, steering);

    }

    void run(){
        ROS_INFO("distance: [%f]; steering: [%f].", lastPose.x(),lastPose.theta());
    }

private:
    ros::NodeHandle n;
    ros::Subscriber timedPose_sub;

    gtsam::Pose2 lastPose;

};

int main(int argc, char** argv) {

    ros::init(argc, argv, "slam_backend");

    iSAM2 backend;

    while(ros::ok()){
        backend.run();
        ros::spinOnce();
    }

    return 0;
}
