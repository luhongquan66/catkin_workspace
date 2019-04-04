#include <pointcloudcluster/pointcloudcluster.hpp>
#include <slam_common/benchmarker.hpp>


PointCloudCluster::PointCloudCluster(ros::NodeHandle nh)
    : nh_(nh)
{
    // Define Publishers and Subscribers here
    pcl_sub_ = nh_.subscribe("/neuavslam/groudPointCloud", 1, &PointCloudCluster::scanCallback, this);
    pcl_pub_ = nh_.advertise<sensor_msgs::PointCloud2>("/cluster_point_cloud", 1);


 }

PointCloudCluster::~PointCloudCluster(){}


void PointCloudCluster::scanCallback(const sensor_msgs::PointCloud2ConstPtr& cloudMessIN)
{
    //程序计时使用
    BENCHMARK_START_NEW_STEP();
    BENCHMARK_START("SAll");

    pcl::PointCloud<pcl::PointXYZ> cloudIn;

    pcl::fromROSMsg(*cloudMessIN,cloudIn);

    for(size_t index = 0 ; index < 14; index++)
    {
        ROS_INFO("%f, %f, %f \n",cloudIn.points[index].x,cloudIn.points[index].y,cloudIn.points[index].z);
    }

    //程序计时使用
    BENCHMARK_STOP("SAll");
}
  // End of class CloudTransformer


