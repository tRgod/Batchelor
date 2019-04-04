
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

typedef pcl::PointCloud<pcl::PointXYZ> PointCloud;;

ros::Publisher pub;
void cloud_cb(const PointCloud::ConstPtr& input )
{

    // Needed defination to get normals and getting the features.
    pcl::PCDWriter writer;
    std::vector<int> inliers;
    pcl::PointCloud<pcl::Normal>::Ptr cloud_normals (new pcl::PointCloud<pcl::Normal>);
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);
    pcl::NormalEstimation<pcl::PointXYZ,pcl::Normal> ne;
    cloud->points=input->points;

    ne.setInputCloud(cloud);
    pcl::search::KdTree<pcl::PointXYZ>::Ptr tree (new pcl::search::KdTree<pcl::PointXYZ>);
    ne.setSearchMethod(tree);
    ne.setRadiusSearch(0.03);
    ne.compute(*cloud_normals);

    pcl::SampleConsensusModelPlane<pcl::PointXYZ>::Ptr model_p(new pcl::SampleConsensusModelPlane<pcl::PointXYZ>(cloud));


    pcl::SampleConsensusModelCone<pcl::PointXYZ,pcl::Normal>::Ptr model_c(new pcl::SampleConsensusModelCone<pcl::PointXYZ,pcl::Normal>(cloud));
    model_c->setInputNormals(cloud_normals);
    model_c->setMinMaxOpeningAngle(0.7,0.9);

    pcl::RandomSampleConsensus<pcl::PointXYZ> ransac (model_c);
    ransac.setSampleConsensusModel(model_c);
    ransac.setDistanceThreshold(10);
    ransac.computeModel();
    ransac.refineModel();
    if(inliers.empty()== true){

    }
    else{
        std::cout<<"no inliners found plz fiz THOR"<<std::endl;
    }
    ransac.getInliers(inliers);

    std::cout<<ransac.getProbability()<<std::endl;

    /*
    BOOST_FOREACH (const pcl::Normal& pt, input_normals->points)
    printf ("\t(%f, %f, %f)\n", pt.normal_x, pt.normal_y, pt.normal_z);
    */
    pcl::copyPointCloud(*input,inliers ,*cloud);
    pub.publish(cloud);
    inliers.clear();
}
int main (int argc, char** argv)
{

    ros::init (argc,argv,"Feature_ekstractor");
    ros::NodeHandle nh1;

    ros::Subscriber sub1 =nh1.subscribe("/output",1, cloud_cb);
    pub=nh1.advertise<sensor_msgs::PointCloud2>("/features",1);
    ros::spin();

}