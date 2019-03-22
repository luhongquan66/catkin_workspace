#include <pointcloudcluster/pointcloudcluster.hpp>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "point_cloud_tf");
  ros::NodeHandle nh;

  PointCloudCluster pointCloudCluster(nh);

  ROS_INFO("This is the catkin workspace template for clustering pointcloud");

  // Spin until ROS is shutdown
  while (ros::ok())
    ros::spin();

  return 0;
}
