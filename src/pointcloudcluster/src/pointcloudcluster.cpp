#include <pointcloudcluster/pointcloudcluster.hpp>

PointCloudCluster::PointCloudCluster(ros::NodeHandle nh)
    : nh_(nh)
{
    // Define Publishers and Subscribers here
    pcl_sub_ = nh_.subscribe("/velodyne_points", 1, &PointCloudCluster::scanCallback, this);
    pcl_pub_ = nh_.advertise<sensor_msgs::PointCloud2>("/cluster_point_cloud", 1);


 }

PointCloudCluster::~PointCloudCluster(){}


void PointCloudCluster::scanCallback(const sensor_msgs::PointCloud2ConstPtr& cloudMessIN)
{

}
  // End of class CloudTransformer


