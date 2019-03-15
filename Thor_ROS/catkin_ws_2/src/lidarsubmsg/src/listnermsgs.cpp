#include <ros/ros.h>
// PCL specific includes
#include <sensor_msgs/PointCloud.h>
#include <sensor_msgs/PointCloud2.h>
#include <sensor_msgs/point_cloud_conversion.h>
#include <pcl_conversions/pcl_conversions.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>

ros::Publisher pub;


void cloud_cd (const sensor_msgs::PointCloudConstPtr& input)
{
	sensor_msgs::PointCloud inputcloud;
	sensor_msgs::PointCloud2 outputCloud;
	inputcloud=*input;
	sensor_msgs::convertPointCloudToPointCloud2(inputcloud, outputCloud);	
	pub.publish(outputCloud);
}

int main (int argc, char** argv)
{
	ros::init (argc, argv, "Point_Cloud_handler");
	ros::NodeHandle nh;
	ros::Subscriber sub = nh.subscribe("/velodyne",1,cloud_cd);

	pub=nh.advertise<sensor_msgs::PointCloud2>("/output",1);

ros::spin();
}
