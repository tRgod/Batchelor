
#include <ros/ros.h>
#include <iostream>
#include <pcl_ros/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/io/pcd_io.h>
#include <pcl/sample_consensus/sac_model_cone.h>
#include <pcl/sample_consensus/ransac.h>



typedef pcl::PointCloud<pcl::PointXYZ> PointCloud;

void cloud_cb(const PointCloud::ConstPtr& input )
{
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud (new PointCloud);
    cloud->width=input->width;
    cloud->height=input->height;
    cloud->points.resize(cloud->width*cloud->height);
    cloud->points=input->points;
std::vector<int> inliers;

pcl::SampleConsensusModelCone<pcl::PointXYZ,pcl::PointXYZ>::Ptr model_c(new pcl::SampleConsensusModelCone<pcl::PointXYZ,pcl::PointXYZ> (cloud));
pcl::RandomSampleConsensus<pcl::PointXYZ> ransac (model_c);
ransac.setDistanceThreshold(.01);
ransac.computeModel();
ransac.getInliers(inliers);
    for (int i = 0; i <inliers.size() ; ++i) {
        std::cout<<inliers[i]<<std::endl;

    }



}
int main (int argc, char** argv)
{

    ros::init (argc,argv,"Feature_ekstractor");
    ros::NodeHandle nh1;

    ros::Subscriber sub1 =nh1.subscribe("/output",1, cloud_cb);
    ros::spin();

     }
