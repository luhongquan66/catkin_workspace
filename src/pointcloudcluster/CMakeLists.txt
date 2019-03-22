cmake_minimum_required(VERSION 2.8.3)
project(pointcloudcluster)

## Add support for C++11, supported in ROS Kinetic and newer
add_definitions(-std=c++11 -DBENCHMARK_ENABLE)


find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  nav_msgs
  sensor_msgs
  roscpp
  rospy
  std_msgs
  tf)

find_package(Eigen3 REQUIRED)
find_package(PCL REQUIRED)

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(
  include
  ${catkin_INCLUDE_DIRS}
  ${PCL_INCLUDE_DIRS}
)

catkin_package(
  CATKIN_DEPENDS geometry_msgs nav_msgs roscpp rospy std_msgs
  DEPENDS EIGEN3 PCL
  INCLUDE_DIRS include
  LIBRARIES libpointcloudcluster
)

add_definitions( -march=native )

add_executable(pointcloudcluster src/pointcloudcluster_node.cpp)
add_library(libpointcloudcluster src/pointcloudcluster.cpp)
target_link_libraries(pointcloudcluster libpointcloudcluster ${catkin_LIBRARIES} ${PCL_LIBRARIES})


