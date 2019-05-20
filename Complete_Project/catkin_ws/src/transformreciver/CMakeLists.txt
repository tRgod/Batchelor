cmake_minimum_required(VERSION 2.8.3)
project(transformreciver)


find_package(catkin REQUIRED COMPONENTS
  roscpp
  geometry_msgs
  tf2
  tf2_ros
)

include_directories(
        # include
        ${catkin_INCLUDE_DIRS}
        # ${PCL_INCLUDE_DIRS}
)
add_executable( transformreciver  src/transformReceiver.cpp)
target_link_libraries(transformreciver ${catkin_LIBRARIES})