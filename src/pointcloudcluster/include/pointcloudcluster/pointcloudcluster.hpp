#include <ros/ros.h>
#include <pcl_conversions/pcl_conversions.h>
#include <pcl_ros/point_cloud.h>
#include <pcl_ros/transforms.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <sensor_msgs/PointCloud2.h>
#include <tf/transform_listener.h>
#include <pcl/conversions.h>


class PointCloudCluster
{
public:
  explicit PointCloudCluster(ros::NodeHandle nh);
  ~PointCloudCluster();

   void scanCallback(const sensor_msgs::PointCloud2ConstPtr& cloudMessIN);

private:
  ros::NodeHandle nh_;
  ros::Subscriber pcl_sub_;
  ros::Publisher pcl_pub_;
  
};  // End of class CloudTransformer

