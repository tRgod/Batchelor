#!/usr/bin/env sh
# generated from catkin/cmake/template/local_setup.sh.in

# since this file is sourced either use the provided _CATKIN_SETUP_DIR
# or fall back to the destination set at configure time
<<<<<<< HEAD
: ${_CATKIN_SETUP_DIR:=/home/gilberg96/Batchelor/Complete_Project/catkin_ws/src/slam_backend/cmake-build-debug/devel}
=======
: ${_CATKIN_SETUP_DIR:=/home/thor/Batchelor/Complete_Project/catkin_ws/src/slam_backend/cmake-build-debug/devel}
>>>>>>> d62d2cc25972dd5ad7f6260987df40e03520bef5
CATKIN_SETUP_UTIL_ARGS="--extend --local"
. "$_CATKIN_SETUP_DIR/setup.sh"
unset CATKIN_SETUP_UTIL_ARGS
