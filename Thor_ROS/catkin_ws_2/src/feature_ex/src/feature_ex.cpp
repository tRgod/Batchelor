
#include <ros/ros.h>
#include <iostream>
#include <pcl_ros/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/filters/extract_indices.h>
#include <boost/foreach.hpp>

#include <pcl/sample_consensus/ransac.h>
#include <pcl/features/normal_3d.h>
#include <pcl/kdtree/kdtree_flann.h>
#include <pcl/filters/extract_indices.h>
#include <pcl/filters/passthrough.h>
#include <pcl/sample_consensus/method_types.h>
#include <pcl/sample_consensus/model_types.h>
#include <pcl/sample_consensus/sac_model_cone.h>
#include <pcl/segmentation/sac_segmentation.h>




typedef pcl::PointCloud<pcl::PointXYZ> PointCloud;
typedef pcl::PointXYZ PoinT;

void cloud_cb(const PointCloud::ConstPtr& input )
{

    // Needed defination to get normals and getting the features.
    pcl::PCDWriter writer;
    pcl::ExtractIndices<PoinT> extract;
    pcl::ExtractIndices<pcl::Normal> extract_normal;
    std::vector<int> inliers;
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>(*input));


    pcl::SampleConsensusModelCone<pcl::PointXYZ,pcl::PointNormal>::Ptr model_c(new pcl::SampleConsensusModelCone<pcl::PointXYZ,pcl::PointNormal>(cloud));
    pcl::RandomSampleConsensus<pcl::PointXYZ> ransac (model_c);
    ransac.setDistanceThreshold(0.01);
    ransac.computeModel();
    ransac.getInliers(inliers);
    /*
    BOOST_FOREACH (const pcl::Normal& pt, input_normals->points)
    printf ("\t(%f, %f, %f)\n", pt.normal_x, pt.normal_y, pt.normal_z);
    */
}
int main (int argc, char** argv)
{

    ros::init (argc,argv,"Feature_ekstractor");
    ros::NodeHandle nh1;

    ros::Subscriber sub1 =nh1.subscribe("/output",1, cloud_cb);
    ros::spin();

}