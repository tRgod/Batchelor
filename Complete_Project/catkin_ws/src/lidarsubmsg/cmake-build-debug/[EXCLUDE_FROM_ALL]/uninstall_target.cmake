if(NOT EXISTS "/home/thor/Desktop/Batchelor/Thor_ROS/catkin_ws_2/src/lidarsubmsg/cmake-build-debug/[EXCLUDE_FROM_ALL]/install_manifest.txt")
  message(FATAL_ERROR "Cannot find install manifest: \"/home/thor/Desktop/Batchelor/Thor_ROS/catkin_ws_2/src/lidarsubmsg/cmake-build-debug/[EXCLUDE_FROM_ALL]/install_manifest.txt\"")
endif()

file(READ "/home/thor/Desktop/Batchelor/Thor_ROS/catkin_ws_2/src/lidarsubmsg/cmake-build-debug/[EXCLUDE_FROM_ALL]/install_manifest.txt" files)
string(REGEX REPLACE "\n" ";" files "${files}")
foreach(file ${files})
  message(STATUS "Uninstalling \"$ENV{DESTDIR}${file}\"")
  if(EXISTS "$ENV{DESTDIR}${file}" OR IS_SYMLINK "$ENV{DESTDIR}${file}")
    exec_program("/home/thor/clion-2019.1/bin/cmake/linux/bin/cmake" ARGS "-E remove \"$ENV{DESTDIR}${file}\""
                 OUTPUT_VARIABLE rm_out RETURN_VALUE rm_retval)
    if(NOT "${rm_retval}" STREQUAL 0)
      message(FATAL_ERROR "Problem when removing \"$ENV{DESTDIR}${file}\"")
    endif()
  else()
    message(STATUS "File \"$ENV{DESTDIR}${file}\" does not exist.")
  endif()
endforeach()

# remove pcl directory in include (removes all files in it!)
message(STATUS "Uninstalling \"/usr/local/include/pcl-1.9\"")
if(EXISTS "/usr/local/include/pcl-1.9")
  exec_program("/home/thor/clion-2019.1/bin/cmake/linux/bin/cmake"
               ARGS "-E remove_directory \"/usr/local/include/pcl-1.9\""
               OUTPUT_VARIABLE rm_out RETURN_VALUE rm_retval)
  if(NOT "${rm_retval}" STREQUAL 0)
    message(FATAL_ERROR "Problem when removing \"/usr/local/include/pcl-1.9\"")
  endif()
else()
  message(STATUS "Directory \"/usr/local/include/pcl-1.9\" does not exist.")
endif()

# remove pcl directory in share (removes all files in it!)
# created by CMakeLists.txt for PCLConfig.cmake
if(EXISTS "/usr/local/share/pcl-1.9")
  file(GLOB_RECURSE CMAKE_CONFIG_FOLDER_FILES FOLLOW_SYMLINKS
       LIST_DIRECTORIES false
       "/usr/local/share/pcl-1.9/*")
  list(LENGTH CMAKE_CONFIG_FOLDER_FILES CMAKE_CONFIG_FOLDER_FILES_NUMBER)
  if(CMAKE_CONFIG_FOLDER_FILES_NUMBER EQUAL 0)
    message(STATUS "Uninstalling \"/usr/local/share/pcl-1.9\"")
    exec_program("/home/thor/clion-2019.1/bin/cmake/linux/bin/cmake"
                 ARGS "-E remove_directory \"/usr/local/share/pcl-1.9\""
                 OUTPUT_VARIABLE rm_out RETURN_VALUE rm_retval)
    if(NOT "${rm_retval}" STREQUAL 0)
      message(FATAL_ERROR "Problem when removing \"/usr/local/share/pcl-1.9\"")
    endif()
  endif()
else(EXISTS "/usr/local/share/pcl-1.9")
  message(STATUS "Directory \"/usr/local/share/pcl-1.9\" does not exist.")
endif()

# remove pcl directory in share/doc (removes all files in it!)
if(OFF)
  message(STATUS "Uninstalling \"/usr/local/share/doc/pcl-1.9\"")
  if(EXISTS "/usr/local/share/doc/pcl-1.9")
    exec_program("/home/thor/clion-2019.1/bin/cmake/linux/bin/cmake"
                 ARGS "-E remove_directory \"/usr/local/share/doc/pcl-1.9\""
                 OUTPUT_VARIABLE rm_out RETURN_VALUE rm_retval)
    if(NOT "${rm_retval}" STREQUAL 0)
      message(FATAL_ERROR "Problem when removing \"/usr/local/share/doc/pcl-1.9\"")
    endif()
  else(EXISTS "/usr/local/share/doc/pcl-1.9")
    message(STATUS "Directory \"/usr/local/share/doc/pcl-1.9\" does not exist.")
  endif()
endif()
