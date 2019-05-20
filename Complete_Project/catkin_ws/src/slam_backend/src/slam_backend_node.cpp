// ROS headers
#include "ros/ros.h"

#include <tf2_ros/buffer.h>
#include <tf2_ros/transform_listener.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.h>
#include <tf2/utils.h>

#include <geometry_msgs/TwistStamped.h>
#include <geometry_msgs/TransformStamped.h>
#include <geometry_msgs/Pose2D.h>

#include <gtsam/geometry/Pose2.h>
#include <gtsam/geometry/Point2.h>

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
    iSAM2(): transformListener(tfBuffer) {
        geometry_msgs::TransformStamped transformStamped;

        timedPose_sub = n.subscribe("twist_stamped", 10, &iSAM2::timedPoseCallback, this);

        try {
            transformStamped = tfBuffer.lookupTransform("velodyneVPL", "world", ros::Time::now(), ros::Duration(60));
        }
        catch (tf2::TransformException &ex){
            ROS_WARN("%s", ex.what());
        }
        tf2::Stamped<tf2::Transform>  transform;
        tf2::fromMsg(transformStamped, transform);

        gtsam::Pose2 pose0 = gtsam::Pose2(transform.getOrigin().x(), transform.getOrigin().y(),tf2::getYaw(transform.getRotation()));

        newFactors.push_back(gtsam::PriorFactor<gtsam::Pose2>(i, pose0, priorNoise));
        initial.insert(i, pose0);
        lastPose = pose0;
        i++;

    }
    void timedPoseCallback(const geometry_msgs::TwistStamped::ConstPtr &msg){
        gtsam::Pose2 odometry(msg->twist.linear.x, 0, msg->twist.angular.z);

        newFactors.push_back(gtsam::BetweenFactor<gtsam::Pose2>(i-1, i, odometry, odoNoise));

        gtsam::Pose2 predictedPose = lastPose.compose(odometry);
        lastPose = predictedPose;
        initial.insert(i, predictedPose);

        i++;

    }

    void rangeBearingCallback(const geometry_msgs::Pose2D::ConstPtr &msg){
        
    }

    void run(){
        initial.print();
    }

private:
    ros::NodeHandle n;
    ros::Subscriber timedPose_sub;
    ros::Subscriber timedRangeBearing_sub;

    tf2_ros::Buffer tfBuffer;
    tf2_ros::TransformListener transformListener;

    gtsam::Vector priorSigmas = gtsam::Vector3( 1, 1, M_PI);
    gtsam::Vector odoSigmas = gtsam::Vector3(0.05, 0.01, 0.2);
    gtsam::Vector rangeSigmas = gtsam::Vector2(0.1, 0.2);

    const gtsam::noiseModel::Base::shared_ptr priorNoise = gtsam::noiseModel::Diagonal::Sigmas(priorSigmas);
    const gtsam::noiseModel::Base::shared_ptr odoNoise = gtsam::noiseModel::Diagonal::Sigmas(odoSigmas);
    const gtsam::noiseModel::Base::shared_ptr rangeNoise = gtsam::noiseModel::Diagonal::Sigmas(rangeSigmas);

    gtsam::NonlinearFactorGraph newFactors;

    gtsam::ISAM2 isam2;

    gtsam::Values initial;

    int i = 0;
    int k = 0;

    gtsam::Pose2 lastPose;


};

int main(int argc, char** argv) {

    ros::init(argc, argv, "slam_backend");

    iSAM2 backend;

    ros::Rate loop_rate(10);

    while(ros::ok()){
        backend.run();
        ros::spinOnce();

        loop_rate.sleep();
    }

    return 0;
}
