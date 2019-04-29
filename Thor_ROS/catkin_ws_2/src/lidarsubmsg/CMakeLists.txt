cmake_minimum_required(VERSION 2.8.3)
project(lidarsubmsg)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages

find_package(catkin REQUIRED COMPONENTS
  pcl_conversions
  pcl_msgs
  pcl_ros
  roscpp
  sensor_msgs
  geometry_msgs
)


include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)
#link_directories(${PCL_LIBRARY_DIRS})
 add_executable(listnermsgs src/listnermsgs.cpp)
 target_link_libraries(listnermsgs ${catkin_LIBRARIES})


