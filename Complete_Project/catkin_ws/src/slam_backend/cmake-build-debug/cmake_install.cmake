<<<<<<< HEAD
# Install script for directory: /home/gilberg96/Batchelor/Complete_Project/catkin_ws/src/slam_backend
=======
# Install script for directory: /home/thor/Batchelor/Complete_Project/catkin_ws/src/slam_backend
>>>>>>> d62d2cc25972dd5ad7f6260987df40e03520bef5

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  
      if (NOT EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}")
        file(MAKE_DIRECTORY "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}")
      endif()
      if (NOT EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/.catkin")
        file(WRITE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/.catkin" "")
      endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/_setup_util.py")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
<<<<<<< HEAD
file(INSTALL DESTINATION "/usr/local" TYPE PROGRAM FILES "/home/gilberg96/Batchelor/Complete_Project/catkin_ws/src/slam_backend/cmake-build-debug/catkin_generated/installspace/_setup_util.py")
=======
file(INSTALL DESTINATION "/usr/local" TYPE PROGRAM FILES "/home/thor/Batchelor/Complete_Project/catkin_ws/src/slam_backend/cmake-build-debug/catkin_generated/installspace/_setup_util.py")
>>>>>>> d62d2cc25972dd5ad7f6260987df40e03520bef5
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/env.sh")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
<<<<<<< HEAD
file(INSTALL DESTINATION "/usr/local" TYPE PROGRAM FILES "/home/gilberg96/Batchelor/Complete_Project/catkin_ws/src/slam_backend/cmake-build-debug/catkin_generated/installspace/env.sh")
=======
file(INSTALL DESTINATION "/usr/local" TYPE PROGRAM FILES "/home/thor/Batchelor/Complete_Project/catkin_ws/src/slam_backend/cmake-build-debug/catkin_generated/installspace/env.sh")
>>>>>>> d62d2cc25972dd5ad7f6260987df40e03520bef5
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/setup.bash;/usr/local/local_setup.bash")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/local" TYPE FILE FILES
<<<<<<< HEAD
    "/home/gilberg96/Batchelor/Complete_Project/catkin_ws/src/slam_backend/cmake-build-debug/catkin_generated/installspace/setup.bash"
    "/home/gilberg96/Batchelor/Complete_Project/catkin_ws/src/slam_backend/cmake-build-debug/catkin_generated/installspace/local_setup.bash"
=======
    "/home/thor/Batchelor/Complete_Project/catkin_ws/src/slam_backend/cmake-build-debug/catkin_generated/installspace/setup.bash"
    "/home/thor/Batchelor/Complete_Project/catkin_ws/src/slam_backend/cmake-build-debug/catkin_generated/installspace/local_setup.bash"
>>>>>>> d62d2cc25972dd5ad7f6260987df40e03520bef5
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/setup.sh;/usr/local/local_setup.sh")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/local" TYPE FILE FILES
<<<<<<< HEAD
    "/home/gilberg96/Batchelor/Complete_Project/catkin_ws/src/slam_backend/cmake-build-debug/catkin_generated/installspace/setup.sh"
    "/home/gilberg96/Batchelor/Complete_Project/catkin_ws/src/slam_backend/cmake-build-debug/catkin_generated/installspace/local_setup.sh"
=======
    "/home/thor/Batchelor/Complete_Project/catkin_ws/src/slam_backend/cmake-build-debug/catkin_generated/installspace/setup.sh"
    "/home/thor/Batchelor/Complete_Project/catkin_ws/src/slam_backend/cmake-build-debug/catkin_generated/installspace/local_setup.sh"
>>>>>>> d62d2cc25972dd5ad7f6260987df40e03520bef5
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/setup.zsh;/usr/local/local_setup.zsh")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/local" TYPE FILE FILES
<<<<<<< HEAD
    "/home/gilberg96/Batchelor/Complete_Project/catkin_ws/src/slam_backend/cmake-build-debug/catkin_generated/installspace/setup.zsh"
    "/home/gilberg96/Batchelor/Complete_Project/catkin_ws/src/slam_backend/cmake-build-debug/catkin_generated/installspace/local_setup.zsh"
=======
    "/home/thor/Batchelor/Complete_Project/catkin_ws/src/slam_backend/cmake-build-debug/catkin_generated/installspace/setup.zsh"
    "/home/thor/Batchelor/Complete_Project/catkin_ws/src/slam_backend/cmake-build-debug/catkin_generated/installspace/local_setup.zsh"
>>>>>>> d62d2cc25972dd5ad7f6260987df40e03520bef5
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/.rosinstall")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
<<<<<<< HEAD
file(INSTALL DESTINATION "/usr/local" TYPE FILE FILES "/home/gilberg96/Batchelor/Complete_Project/catkin_ws/src/slam_backend/cmake-build-debug/catkin_generated/installspace/.rosinstall")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/slam_backend/msg" TYPE FILE FILES "/home/gilberg96/Batchelor/Complete_Project/catkin_ws/src/slam_backend/msg/TimedPose.msg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/slam_backend/cmake" TYPE FILE FILES "/home/gilberg96/Batchelor/Complete_Project/catkin_ws/src/slam_backend/cmake-build-debug/catkin_generated/installspace/slam_backend-msg-paths.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "/home/gilberg96/Batchelor/Complete_Project/catkin_ws/src/slam_backend/cmake-build-debug/devel/include/slam_backend")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/roseus/ros" TYPE DIRECTORY FILES "/home/gilberg96/Batchelor/Complete_Project/catkin_ws/src/slam_backend/cmake-build-debug/devel/share/roseus/ros/slam_backend")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/common-lisp/ros" TYPE DIRECTORY FILES "/home/gilberg96/Batchelor/Complete_Project/catkin_ws/src/slam_backend/cmake-build-debug/devel/share/common-lisp/ros/slam_backend")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gennodejs/ros" TYPE DIRECTORY FILES "/home/gilberg96/Batchelor/Complete_Project/catkin_ws/src/slam_backend/cmake-build-debug/devel/share/gennodejs/ros/slam_backend")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND "/usr/bin/python2" -m compileall "/home/gilberg96/Batchelor/Complete_Project/catkin_ws/src/slam_backend/cmake-build-debug/devel/lib/python2.7/dist-packages/slam_backend")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages" TYPE DIRECTORY FILES "/home/gilberg96/Batchelor/Complete_Project/catkin_ws/src/slam_backend/cmake-build-debug/devel/lib/python2.7/dist-packages/slam_backend")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/gilberg96/Batchelor/Complete_Project/catkin_ws/src/slam_backend/cmake-build-debug/catkin_generated/installspace/slam_backend.pc")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/slam_backend/cmake" TYPE FILE FILES "/home/gilberg96/Batchelor/Complete_Project/catkin_ws/src/slam_backend/cmake-build-debug/catkin_generated/installspace/slam_backend-msg-extras.cmake")
=======
file(INSTALL DESTINATION "/usr/local" TYPE FILE FILES "/home/thor/Batchelor/Complete_Project/catkin_ws/src/slam_backend/cmake-build-debug/catkin_generated/installspace/.rosinstall")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/slam_backend/msg" TYPE FILE FILES "/home/thor/Batchelor/Complete_Project/catkin_ws/src/slam_backend/msg/TimedPose.msg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/slam_backend/cmake" TYPE FILE FILES "/home/thor/Batchelor/Complete_Project/catkin_ws/src/slam_backend/cmake-build-debug/catkin_generated/installspace/slam_backend-msg-paths.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "/home/thor/Batchelor/Complete_Project/catkin_ws/src/slam_backend/cmake-build-debug/devel/include/slam_backend")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/roseus/ros" TYPE DIRECTORY FILES "/home/thor/Batchelor/Complete_Project/catkin_ws/src/slam_backend/cmake-build-debug/devel/share/roseus/ros/slam_backend")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/common-lisp/ros" TYPE DIRECTORY FILES "/home/thor/Batchelor/Complete_Project/catkin_ws/src/slam_backend/cmake-build-debug/devel/share/common-lisp/ros/slam_backend")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gennodejs/ros" TYPE DIRECTORY FILES "/home/thor/Batchelor/Complete_Project/catkin_ws/src/slam_backend/cmake-build-debug/devel/share/gennodejs/ros/slam_backend")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND "/usr/bin/python2" -m compileall "/home/thor/Batchelor/Complete_Project/catkin_ws/src/slam_backend/cmake-build-debug/devel/lib/python2.7/dist-packages/slam_backend")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages" TYPE DIRECTORY FILES "/home/thor/Batchelor/Complete_Project/catkin_ws/src/slam_backend/cmake-build-debug/devel/lib/python2.7/dist-packages/slam_backend")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/thor/Batchelor/Complete_Project/catkin_ws/src/slam_backend/cmake-build-debug/catkin_generated/installspace/slam_backend.pc")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/slam_backend/cmake" TYPE FILE FILES "/home/thor/Batchelor/Complete_Project/catkin_ws/src/slam_backend/cmake-build-debug/catkin_generated/installspace/slam_backend-msg-extras.cmake")
>>>>>>> d62d2cc25972dd5ad7f6260987df40e03520bef5
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/slam_backend/cmake" TYPE FILE FILES
<<<<<<< HEAD
    "/home/gilberg96/Batchelor/Complete_Project/catkin_ws/src/slam_backend/cmake-build-debug/catkin_generated/installspace/slam_backendConfig.cmake"
    "/home/gilberg96/Batchelor/Complete_Project/catkin_ws/src/slam_backend/cmake-build-debug/catkin_generated/installspace/slam_backendConfig-version.cmake"
=======
    "/home/thor/Batchelor/Complete_Project/catkin_ws/src/slam_backend/cmake-build-debug/catkin_generated/installspace/slam_backendConfig.cmake"
    "/home/thor/Batchelor/Complete_Project/catkin_ws/src/slam_backend/cmake-build-debug/catkin_generated/installspace/slam_backendConfig-version.cmake"
>>>>>>> d62d2cc25972dd5ad7f6260987df40e03520bef5
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
<<<<<<< HEAD
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/slam_backend" TYPE FILE FILES "/home/gilberg96/Batchelor/Complete_Project/catkin_ws/src/slam_backend/package.xml")
=======
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/slam_backend" TYPE FILE FILES "/home/thor/Batchelor/Complete_Project/catkin_ws/src/slam_backend/package.xml")
>>>>>>> d62d2cc25972dd5ad7f6260987df40e03520bef5
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
<<<<<<< HEAD
  include("/home/gilberg96/Batchelor/Complete_Project/catkin_ws/src/slam_backend/cmake-build-debug/gtest/cmake_install.cmake")
=======
  include("/home/thor/Batchelor/Complete_Project/catkin_ws/src/slam_backend/cmake-build-debug/gtest/cmake_install.cmake")
>>>>>>> d62d2cc25972dd5ad7f6260987df40e03520bef5

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
<<<<<<< HEAD
file(WRITE "/home/gilberg96/Batchelor/Complete_Project/catkin_ws/src/slam_backend/cmake-build-debug/${CMAKE_INSTALL_MANIFEST}"
=======
file(WRITE "/home/thor/Batchelor/Complete_Project/catkin_ws/src/slam_backend/cmake-build-debug/${CMAKE_INSTALL_MANIFEST}"
>>>>>>> d62d2cc25972dd5ad7f6260987df40e03520bef5
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")