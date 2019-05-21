
cmake_minimum_required(VERSION 2.8.3)
project(transform_receiver)


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
add_executable(transform_receiver  src/transformReceiver.cpp)
target_link_libraries(transform_receiver ${catkin_LIBRARIES})
