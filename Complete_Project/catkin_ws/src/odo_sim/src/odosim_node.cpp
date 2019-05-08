//
// Created by gilberg96 on 5/7/19.
//

#include <ros/ros.h>
#include <geometry_msgs/PoseStamped.h>

class OdoSim{
public:
    OdoSim(){

    }
    void poseStampedCallback(const geometry_msgs::PoseStamped::ConstPtr &msg){
        double deltatime, deltax, deltay, velocity;
        deltatime = msg->header.stamp.toSec()-previoustime;
        deltax = msg->pose.position.x-previousx;
        deltay = msg->pose.position.y-previousy;
        velocity = sqrt(pow(deltax,2)+pow(deltay,2))/deltatime;



    }

private:
    double previousx;
    double previousy;
    double previoustime;

};


int main(int argc, char** argv){
    ros::init(argc, argv, "odoSim");
    ros::NodeHandle n;
    ros::Subscriber poseStamped_sub;
    ros::Publisher poseStamped_pub;

    ros::spin();

    return 0;
}
