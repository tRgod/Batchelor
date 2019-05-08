//
// Created by gilberg96 on 5/1/19.
//

#include "ros/ros.h"
#include "std_msgs/Float32.h"
#include "std_msgs/UInt16.h"

#include <slam_backend/TimedPose.h>

class TimedPose {
public:
    TimedPose(double maxLeft, double maxRight, int N):deltaDist(0),deltaSteer(0),lastSteeringAngle(0), lastTime(ros::Time::now().toSec()),AngleResolution(setAngleResolution(maxLeft,maxRight,N)){
        speed_sub = n.subscribe("speed", 10, &TimedPose::velocityCallback, this);
        steering_sub = n.subscribe("steering_monitor", 10, &TimedPose::steeringCallback, this);
        timedPose_pub = n.advertise<slam_backend::TimedPose>("timed_Pose", 10);

    }
    void velocityCallback(const std_msgs::Float32::ConstPtr msg){
        double velocity = double(msg->data);
        double currentTime = ros::Time::now().toSec();
        double duration = currentTime-lastTime;
        deltaDist = velocity*duration;
    }

    void steeringCallback(const std_msgs::UInt16::ConstPtr msg){
        int currentSteeringAngle = int(msg->data);
        deltaSteer = (currentSteeringAngle-lastSteeringAngle)*AngleResolution*M_PI/180;
        lastSteeringAngle = currentSteeringAngle;

    }

    static double setAngleResolution(double maxLeft, double maxRight, int N) {
        return (maxRight - maxLeft) / N;
    }

    void publishTimedPose2(){
        slam_backend::TimedPose timedPose;
        timedPose.time = ros::Time::now().toSec();
        timedPose.dist = deltaDist;
        timedPose.steer = deltaSteer;
        timedPose_pub.publish(timedPose);
        //ROS_INFO("Time: [%f] s. Distance: [%f] m. Steering: [%f] rad", timedPose.time, timedPose.dist, timedPose.steer);

    }

protected:
    ros::NodeHandle n;
    ros::Subscriber speed_sub;
    ros::Subscriber steering_sub;
    ros::Publisher timedPose_pub;
    double lastTime;
    double deltaDist; // Translated distance (m)
    double deltaSteer; // Change in steering (rad)
    int lastSteeringAngle;
    double AngleResolution;


};

int main(int argc, char **argv){

    ros::init(argc,argv,"timed_pose");
    TimedPose timedPose(-40,40,100); // set maximum steering angles and quantization.

    ros::Rate loop_rate(10); // set loop rate to 10Hz i.e. once every 100 ms.

    while(ros::ok()) {

        timedPose.publishTimedPose2();
        ros::spinOnce();

        loop_rate.sleep();
    }

    return 0;
}
