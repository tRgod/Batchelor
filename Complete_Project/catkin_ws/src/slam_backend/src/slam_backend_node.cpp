// ROS headers
#include "ros/ros.h"

#include <tf2_ros/buffer.h>
#include <tf2_ros/transform_listener.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.h>
#include <tf2/utils.h>

#include <geometry_msgs/TwistStamped.h>
#include <geometry_msgs/TransformStamped.h>
#include <geometry_msgs/PointStamped.h>

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

typedef boost::tuple<ros::Time, double, double> TimedBearingRange;

class iSAM2{
public:
    iSAM2(): transformListener(tfBuffer) {
        geometry_msgs::TransformStamped transformStamped;

        timedPose_sub = n.subscribe("twist_stamped", 10, &iSAM2::timedPoseCallback, this);
        bearingRange_sub = n.subscribe("pose", 1000, &iSAM2::rangeBearingCallback, this);

        odometry_pub = n.advertise<geometry_msgs::PoseStamped>("predicted_poses", 10);
        iSAM2_pub = n.advertise<geometry_msgs::PoseStamped>("isam2_poses", 10);
        landmark_pub = n.advertise<geometry_msgs::PointStamped>("landmarks", 100);


        /*try {
            transformStamped = tfBuffer.lookupTransform("velodyneVPL", "world", ros::Time(0.001), ros::Duration(60));
        }
        catch (tf2::TransformException &ex){
            ROS_WARN("%s", ex.what());
        }
        tf2::Stamped<tf2::Transform>  transform;
        tf2::fromMsg(transformStamped, transform);

        gtsam::Pose2 pose0 = gtsam::Pose2(transform.getOrigin().x(), transform.getOrigin().y(),tf2::getYaw(transform.getRotation()));*/
        gtsam::Pose2 pose0 = gtsam::Pose2(-12.5, 0, 0);

        newFactors.push_back(gtsam::PriorFactor<gtsam::Pose2>(gtsam::symbol('x',i), pose0, priorNoise));
        initial.insert(gtsam::symbol('x',i), pose0);
        lastPose = pose0;
        i++;

    }

    int findCorrespondences(gtsam::Point2 &point){

        if (foundLandmarks.empty()==true) {
            foundLandmarks.push_back(point);
            initial.insert(gtsam::symbol('l', 0), point);
            return 0;
        }
        for (int i = 0; i < foundLandmarks.size()-1; i++) {
            if(sqrt(pow(foundLandmarks[i].x()-point.x(),2)+pow(foundLandmarks[i].y()-point.y(),2)) < 0.5){
                return i;
            }
        }
        foundLandmarks.push_back(point);
        initial.insert(gtsam::symbol('l', foundLandmarks.size()-1), point);
        return foundLandmarks.size()-1;


    }

    void publishOdometry(gtsam::Pose2 &pose, const ros::Time &time) {
        geometry_msgs::PoseStamped odometryPose;
        odometryPose.header.stamp = time;
        odometryPose.pose.position.x = pose.x();
        odometryPose.pose.position.y = pose.y();
        odometryPose.pose.orientation.z = pose.theta();
        odometry_pub.publish(odometryPose);
    }

    void publishLandmarks(gtsam::Point2 &point, const ros::Time &time){
        geometry_msgs::PointStamped landmark;
        landmark.header.stamp = time;
        landmark.point.x = point.x();
        landmark.point.y = point.y();
        landmark_pub.publish(landmark);
    }

    void publishISAM2Pose(gtsam::Pose2 &pose, const ros::Time &time){
        geometry_msgs::PoseStamped iSAM2Pose;
        iSAM2Pose.header.stamp = time;
        iSAM2Pose.pose.position.x = pose.x();
        iSAM2Pose.pose.position.y = pose.y();
        iSAM2Pose.pose.orientation.z = pose.theta();
        iSAM2_pub.publish(iSAM2Pose);
    }

    void timedPoseCallback(const geometry_msgs::TwistStamped::ConstPtr &msg){

        geometry_msgs::PoseStamped iSAM2Pose;
        geometry_msgs::PointStamped landmarkPosition;

        gtsam::Pose2 odometry(msg->twist.linear.x, 0, msg->twist.angular.z);

        newFactors.push_back(gtsam::BetweenFactor<gtsam::Pose2>(gtsam::symbol('x', i-1), gtsam::symbol('x', i), odometry, odoNoise));

        gtsam::Pose2 predictedPose = lastPose.compose(odometry);

        lastPose = predictedPose;

        publishOdometry(lastPose, msg->header.stamp);

        //std::cout << "time: " << msg->header.stamp << " x: " << lastPose.x() << " y: " << lastPose.y() << " theta: " << lastPose.theta() << std::endl;

        initial.insert(gtsam::symbol('x', i), predictedPose);

        while (k < K && msg->header.stamp >= boost::get<0>(timedMeasurements[k])){
            double x = boost::get<1>(timedMeasurements[k]), y = boost::get<2>(timedMeasurements[k]);
            double range = sqrt(pow(x, 2)+pow(y,2));
            double bearing = atan2(y, x);
            int landmarkID;

            gtsam::Point2 predictedPosition(cos(lastPose.theta())*x-sin(lastPose.theta())*y+lastPose.x(), sin(lastPose.theta())*x+cos(lastPose.theta())*y+lastPose.y());
            landmarkID = findCorrespondences(predictedPosition);

            newFactors.push_back(gtsam::BearingRangeFactor<gtsam::Pose2, gtsam::Point2>(gtsam::symbol('x', i), gtsam::symbol('l',landmarkID),bearing, range, rangeNoise));

            k=k+1;
            countK=countK+1;
            publishLandmarks(predictedPosition, boost::get<0>(timedMeasurements[k]));
        }

        if((countK > incK) && (k > minK)){
            if(!initialized){
                gtsam::LevenbergMarquardtOptimizer batchOptimizer(newFactors, initial);
                initial = batchOptimizer.optimize();
                initialized = true;
            }
            isam2.update(newFactors, initial);
            gtsam::Values result = isam2.calculateEstimate();
            lastPose = result.at<gtsam::Pose2>(gtsam::symbol('x',i));
            publishISAM2Pose(lastPose, msg->header.stamp);
            newFactors = gtsam::NonlinearFactorGraph();
            initial = gtsam::Values();
            countK = 0;
        }

        i++;

    }

    void rangeBearingCallback(const geometry_msgs::PointStamped::ConstPtr &msg){

        timedMeasurements.push_back(TimedBearingRange(msg->header.stamp,msg->point.x,msg->point.y));
        //std::cout << msg->header.stamp.toSec() << " " << msg->point.x << " " << msg->point.y << std::endl;
        K++;
    }

private:
    ros::NodeHandle n;
    ros::Subscriber timedPose_sub;
    ros::Subscriber timedRangeBearing_sub;
    ros::Subscriber bearingRange_sub;

    ros::Publisher odometry_pub;
    ros::Publisher iSAM2_pub;
    ros::Publisher landmark_pub;

    tf2_ros::Buffer tfBuffer;
    tf2_ros::TransformListener transformListener;

    gtsam::Vector priorSigmas = gtsam::Vector3( 0.01, 0.01, 0.05);
    gtsam::Vector odoSigmas = gtsam::Vector3(0.5, 0.5, 0.1);
    gtsam::Vector rangeSigmas = gtsam::Vector2(0.05, 0.1);

    const gtsam::noiseModel::Base::shared_ptr priorNoise = gtsam::noiseModel::Diagonal::Sigmas(priorSigmas);
    const gtsam::noiseModel::Base::shared_ptr odoNoise = gtsam::noiseModel::Diagonal::Sigmas(odoSigmas);
    const gtsam::noiseModel::Base::shared_ptr rangeNoise = gtsam::noiseModel::Diagonal::Sigmas(rangeSigmas);

    gtsam::NonlinearFactorGraph newFactors;

    gtsam::ISAM2 isam2;

    gtsam::Values initial;

    int i = 0;
    int k = 0;
    int K = 0;
    int incK = 15;
    int countK = 0;
    int minK = 100;

    bool initialized = true;

    gtsam::Pose2 lastPose;

    std::vector<TimedBearingRange> timedMeasurements;
    std::vector<gtsam::Point2> foundLandmarks;

};

int main(int argc, char** argv) {

    ros::init(argc, argv, "slam_backend_node");

    iSAM2 backend;

    ros::spin();

    return 0;
}
