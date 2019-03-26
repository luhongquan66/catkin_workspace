cmake_minimum_required(VERSION 2.8.3)
project(pointcloudcluster)

## Add support for C++11, supported in ROS Kinetic and newer
add_definitions(-std=c++11 -DBENCHMARK_ENABLE)

find_package(catkin_simple 0.1.0 REQUIRED)
find_package(Eigen3 REQUIRED)
find_package(PCL REQUIRED)

catkin_simple(ALL_DEPS_REQUIRED)

cs_add_library(${PROJECT_NAME}
    src/pointcloudcluster.cpp
    )

include_directories(
  ${PCL_INCLUDE_DIRS}
)


cs_add_executable(pointcloudcluster_node src/pointcloudcluster_node.cpp)
target_link_libraries(pointcloudcluster_node ${PROJECT_NAME})

cs_install()
cs_export()



