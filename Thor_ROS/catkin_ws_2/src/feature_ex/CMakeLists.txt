cmake_minimum_required(VERSION 2.8.3)
project(feature_ex)


#find_package( PCL 1.9.1 REQUIRED )
find_package( catkin REQUIRED COMPONENTS
  pcl_msgs
  pcl_ros
  roscpp
  std_msgs
  geometry_msgs
)

#add_definitions(${PCL_DEFINITIONS})
include_directories(
# include
  ${catkin_INCLUDE_DIRS}
 # ${PCL_INCLUDE_DIRS}
)
#LINK_DIRECTORIES(${PCL_LIBRARY_DIRS})
add_executable(feature_ex  src/feature_ex_segmentation.cpp)
target_link_libraries(feature_ex ${catkin_LIBRARIES})
