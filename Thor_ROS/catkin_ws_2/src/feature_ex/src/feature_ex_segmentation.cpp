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
#include <pcl/sample_consensus/sac_model.h>
#include <pcl/sample_consensus/sac_model_plane.h>
#include <pcl/filters/plane_clipper3D.h>
#include <tf/transform_listener.h>
#include <geometry_msgs/Pose2D.h>
#include <Eigen/Dense>
#include <pcl/segmentation/extract_clusters.h>


ros::Publisher pub_pointcloud;
ros::Publisher pub_posemsgs;

void cloud_cb(const pcl::PointCloud<pcl::PointXYZ>::ConstPtr& input)
{
    ros::WallTime start_,end_;
    start_=ros::WallTime::now();
    geometry_msgs::Pose2D madausneedthis;
    pcl::PassThrough<pcl::PointXYZ> pass;
    pcl::NormalEstimation<pcl::PointXYZ, pcl::Normal> ne;

    pcl::SACSegmentationFromNormals<pcl::PointXYZ,pcl::Normal> seg;
    pcl::ExtractIndices<pcl::PointXYZ> extract;
    pcl::ExtractIndices<pcl::Normal> extract_normals;
    pcl::search::KdTree<pcl::PointXYZ>::Ptr tree(new pcl::search::KdTree<pcl::PointXYZ>());

    //data

    //Creating a cloud object to hold the input cloud
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZ>);
    //filling the cloud with data
    cloud->width=input->width;
    cloud->height=input->height;
    cloud->points=input->points;;
    cloud->header=input->header;
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_filtered1(new pcl::PointCloud<pcl::PointXYZ>);
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_filtered(new pcl::PointCloud<pcl::PointXYZ>);
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_filtered3(new pcl::PointCloud<pcl::PointXYZ>);
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_filtered4(new pcl::PointCloud<pcl::PointXYZ>);
    pcl::PointCloud<pcl::Normal>::Ptr cloud_normals (new pcl::PointCloud<pcl::Normal>);
    pcl::PointCloud<pcl::Normal>::Ptr cloud_normals2 (new pcl::PointCloud<pcl::Normal>);
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_filtered2 (new pcl::PointCloud<pcl::PointXYZ>);
    pcl::ModelCoefficients::Ptr coefficients_plane (new pcl::ModelCoefficients), coefficients_cone (new pcl::ModelCoefficients);
    pcl::PointIndices::Ptr inliers_plane (new pcl::PointIndices), inliners_cone (new pcl::PointIndices);

    //building a passthrough filter to remove NaNs
    pass.setInputCloud(cloud);
    pass.setFilterFieldName("z");
    pass.setFilterLimits(-0.25,0.1);
    pass.setNegative(false);
    pass.filter(*cloud_filtered3);
    //build a pass through filter to remove points behind the velodyne sensor
    pass.setInputCloud(cloud_filtered3);
    pass.setFilterFieldName("x");
    pass.setFilterLimits(-100,0.03);
    pass.setNegative(true);
    pass.filter(*cloud_filtered);
    //build a pass throu filter til limit the points fromt he side.
    pass.setInputCloud(cloud_filtered);
    pass.setFilterFieldName("y");
    pass.setFilterLimits(-3,3);
    pass.setNegative(false);
    pass.filter(*cloud_filtered4);


    //Estimate point normals
    ne.setSearchMethod(tree);
    ne.setInputCloud(cloud_filtered4);
    ne.setKSearch(50);
    ne.compute(*cloud_normals);

    //creating the segmentation object for the planar model and set all the parameters
    seg.setOptimizeCoefficients(true);
    seg.setModelType(pcl::SACMODEL_NORMAL_PLANE);
    seg.setNormalDistanceWeight(0.1);
    seg.setMethodType(pcl::SAC_RANSAC);
    seg.setMaxIterations(100);
    seg.setDistanceThreshold(0.15 );
    seg.setInputCloud(cloud_filtered4);
    seg.setInputNormals(cloud_normals);
    seg.segment(*inliers_plane,*coefficients_plane);

    //Extract the planar inliners
    extract.setInputCloud(cloud_filtered4);
    extract.setIndices(inliers_plane);
    extract.setNegative(false);
    //create cloud for planmodel
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_plane (new pcl::PointCloud<pcl::PointXYZ>);
    extract.filter(*cloud_plane);
    cloud_plane->header=input->header;

    //Removing plannar inliers from the cloud
    extract.setNegative(true);
    extract.filter(*cloud_filtered4);
    extract_normals.setNegative(true);
    extract_normals.setInputCloud(cloud_normals);
    extract_normals.setIndices(inliers_plane);
    extract_normals.filter(*cloud_normals2);

    //create kdtree object for the search method of extraction

    //create segmentation object for cone segmentation and setting parameters.
    int nr_points = (int) cloud_filtered4->points.size();
    pcl::PointCloud<pcl::PointXYZ>::Ptr  cloud_f (new pcl::PointCloud<pcl::PointXYZ>);

        if (cloud_filtered4->points.size() != 0) {
            seg.setOptimizeCoefficients(true);
            seg.setModelType(pcl::SACMODEL_CONE);
            seg.setMethodType(pcl::SAC_RANSAC);
            seg.setNormalDistanceWeight(0.1);
            seg.setMaxIterations(150);
            seg.setDistanceThreshold(0.005);
            seg.setRadiusLimits(0, 0.4);
            seg.setMinMaxOpeningAngle(0.4, 0.8);

            while (cloud_filtered4->points.size() >0.6*nr_points) {
                seg.setInputCloud(cloud_filtered4);
                seg.setInputNormals(cloud_normals2);
                seg.segment(*inliners_cone, *coefficients_cone);
                if(inliners_cone->indices.size() ==0)
                {
                    break;
                }
                std::cout << *coefficients_cone << std::endl;
                if (coefficients_cone->values[0] < 100 && coefficients_cone->values[0] > 0) {
                    madausneedthis.x = coefficients_cone->values[0];
                    madausneedthis.y = coefficients_cone->values[1];
                    madausneedthis.theta = atan2(coefficients_cone->values[0], coefficients_cone->values[1]);
                }
                //ekstract the cone objects.
                extract.setInputCloud(cloud_filtered4);
                extract.setIndices(inliners_cone);
                extract.setNegative(false);
                //create cone cloud
                pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_cone(new pcl::PointCloud<pcl::PointXYZ>());
                extract.filter(*cloud_cone);
                extract.setNegative(true);
                extract.filter(*cloud_f);
                *cloud_filtered4=*cloud_f;
                ne.setSearchMethod(tree);
                ne.setInputCloud(cloud_filtered4);
                ne.setKSearch(50);
                ne.compute(*cloud_normals);
                cloud_normals2=cloud_normals;


                cloud_cone->header = input->header;
                if(cloud_cone->points.size()>100) {
                    pub_pointcloud.publish(cloud_cone);
                    pub_posemsgs.publish(madausneedthis);
                }
            }
        }

        end_=ros::WallTime::now();
        double execution_time=(end_- start_).toNSec()*1e-06;
        ROS_INFO_STREAM("Execution time (ms) :"  << execution_time);
    }



int main (int argc, char** argv)
{

    ros::init (argc,argv,"Feature_ekstractor");
    ros::NodeHandle nh1;
    tf::TransformListener listener;
    ros::Subscriber sub1 =nh1.subscribe("/output",1, cloud_cb);

    pub_pointcloud=nh1.advertise<sensor_msgs::PointCloud2>("/features",1);
    pub_posemsgs=nh1.advertise<geometry_msgs::Pose2D>("/pose",1);
    ros::spin();

}

