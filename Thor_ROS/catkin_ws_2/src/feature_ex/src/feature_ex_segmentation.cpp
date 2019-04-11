#include <ros/ros.h>
#include <iostream>
#include <pcl_ros/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/point_types.h>
#include <pcl/sample_consensus/ransac.h>
#include <pcl/features/normal_3d.h>
#include <pcl/kdtree/kdtree_flann.h>
#include <pcl/filters/extract_indices.h>
#include <pcl/filters/passthrough.h>
#include <pcl/sample_consensus/method_types.h>
#include <pcl/sample_consensus/model_types.h>
#include <pcl/sample_consensus/sac_model_cone.h>
#include <pcl/segmentation/sac_segmentation.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <pcl/sample_consensus/sac_model.h>
#include <pcl/sample_consensus/sac_model_plane.h>
#include <pcl/filters/plane_clipper3D.h>
ros::Publisher pub;

void cloud_cb(const pcl::PointCloud<pcl::PointXYZ>::ConstPtr& input)
{
    //Creating a cloud object to hold the input cloud
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZ>);
    //filling the cloud with data
    cloud->width=input->width;
    cloud->height=input->height;
    cloud->points=input->points;
    cloud->header=input->header;
    // defina a serch tree to find normals
    pcl::search::Search<pcl::PointXYZ>::Ptr tree (new pcl::search::KdTree<pcl::PointXYZ>);
    pcl::PointCloud<pcl::Normal>::Ptr Normals (new pcl::PointCloud<pcl::Normal>);
    pcl::NormalEstimation<pcl::PointXYZ,pcl::Normal> normal_estimator;
    normal_estimator.setSearchMethod(tree);
    normal_estimator.setInputCloud(cloud);
    normal_estimator.setKSearch(50);
    normal_estimator.compute(*Normals);
   /* BOOST_FOREACH (const pcl::Normal& pt, Normals->points)
                    printf ("\t(%f, %f, %f)\n", pt.normal_x, pt.normal_y, pt.normal_z);
*/
    pcl::ModelCoefficients::Ptr coefficients (new pcl::ModelCoefficients);
    pcl::PointIndices::Ptr inliers (new pcl::PointIndices);

    //create segmentation object
    pcl::SACSegmentation<pcl::PointXYZ> seg;

    seg.setOptimizeCoefficients(true);

    seg.setModelType(pcl::SACMODEL_PLANE);
    seg.setMethodType(pcl::SAC_RANSAC);
    seg.setDistanceThreshold(0.01);
    seg.setInputCloud(cloud);
    seg.segment (*inliers, *coefficients);
    pcl::PointCloud<pcl::PointXYZ>::Ptr final_cloud(new pcl::PointCloud<pcl::PointXYZ>);
    if (inliers->indices.size () == 0)
    {
        PCL_ERROR ("Could not estimate a planar model for the given dataset.");

    }

    std::cerr << "Model coefficients: " << coefficients->values[0] << " "
              << coefficients->values[1] << " "
              << coefficients->values[2] << " "
              << coefficients->values[3] << std::endl;


    pcl::copyPointCloud( *cloud,inliers,*final_cloud);

    pub.publish(final_cloud);


}
int main (int argc, char** argv)
{

    ros::init (argc,argv,"Feature_ekstractor");
    ros::NodeHandle nh1;

    ros::Subscriber sub1 =nh1.subscribe("/output",1, cloud_cb);
    pub=nh1.advertise<sensor_msgs::PointCloud2>("/features",1);
    ros::spin();

}

