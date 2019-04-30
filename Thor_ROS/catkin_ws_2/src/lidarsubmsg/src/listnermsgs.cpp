#include <ros/ros.h>
// PCL specific includes
#include <sensor_msgs/PointCloud.h>
#include <sensor_msgs/PointCloud2.h>
#include <geometry_msgs/Pose.h>
#include <sensor_msgs/point_cloud_conversion.h>
#include <pcl_conversions/pcl_conversions.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/filters/passthrough.h>
#include <pcl/conversions.h>
#include <pcl_ros/transforms.h>
#include <tf/transform_listener.h>
#include <message_filters/subscriber.h>
#include <message_filters/time_synchronizer.h>

ros::Publisher pub;
tf::TransformListener *tf_listner;

void cloud_cb (const sensor_msgs::PointCloudConstPtr& input)
{
    //convert pointcloud to a pointcloud 2
    pcl::PassThrough<pcl::PointXYZ> pass;
	sensor_msgs::PointCloud inputcloud;
	sensor_msgs::PointCloud2 outputCloud;
	sensor_msgs::PointCloud2 msg_cloud;
	pcl::PCLPointCloud2 pcl2 ;
	inputcloud=*input;

	tf_listner->waitForTransform("world","velodyneVPL",input->header.stamp,ros::Duration(0.1));
	sensor_msgs::convertPointCloudToPointCloud2(inputcloud, outputCloud);
    std::cout<< inputcloud.header<<std::endl;

    //converting to at pcl::Pointcloud
	pcl::PCLPointCloud2 pcl_pc2;
    pcl::PointCloud<pcl::PointXYZ>::Ptr temp_cloud1(new pcl::PointCloud<pcl::PointXYZ>);
    pcl::PointCloud<pcl::PointXYZ>::Ptr temp_cloud2(new pcl::PointCloud<pcl::PointXYZ>);
	pcl_conversions::toPCL(outputCloud,pcl_pc2);


	pcl::PointCloud<pcl::PointXYZ>::Ptr temp_cloud(new pcl::PointCloud<pcl::PointXYZ>);
	pcl::fromPCLPointCloud2(pcl_pc2,*temp_cloud);
   pcl_ros::transformPointCloud("/world",*temp_cloud,*temp_cloud1,*tf_listner);
    	// creating the pass throug filter
    pass.setInputCloud(temp_cloud1);
    pass.setFilterFieldName("y");
    pass.setFilterLimits(-1,0.1);
    pass.setFilterLimitsNegative(true);
    pass.filter(*temp_cloud2);
	pcl::toROSMsg(*temp_cloud1,msg_cloud);


	//std::cout<<outputCloud.header<< "Heigt: "<<outputCloud.height<< "Width : "<<outputCloud.width<<std::endl; // debug information
	pub.publish(msg_cloud);
}

int main (int argc, char** argv)
{
	ros::init (argc, argv, "Point_Cloud_handler");
	ros::NodeHandle nh;
//	message_filters::Subscriber<sensor_msgs::PointCloudConstPtr> pointcloud_sub(nh,"/output",1);
//	message_filters::Subscriber<geometry_msgs::Pose> pose_sub(nh,"/Transform_listner",1);
//    message_filters::TimeSynchronizer<sensor_msgs::PointCloudConstPtr,geometry_msgs::Pose> sync(pointcloud_sub,pose_sub,10);
  //  sync.registerCallback(boost::bind(&callback, _1,_2));
	ros::Subscriber sub = nh.subscribe("/velodyne",1,cloud_cb);
    tf_listner = new tf::TransformListener();
	pub=nh.advertise<pcl::PCLPointCloud2>("/output",1);

ros::spin();
return 0;
}
