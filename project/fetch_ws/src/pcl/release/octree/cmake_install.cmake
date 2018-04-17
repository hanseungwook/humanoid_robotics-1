# Install script for directory: /home/kathleen/humanoid_robotics/project/fetch_ws/src/pcl/octree

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "None")
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

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "pcl_octree")
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libpcl_octree.so.1.8.1.99"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libpcl_octree.so.1.8"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libpcl_octree.so"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHECK
           FILE "${file}"
           RPATH "/usr/lib")
    endif()
  endforeach()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
    "/home/kathleen/humanoid_robotics/project/fetch_ws/src/pcl/release/lib/libpcl_octree.so.1.8.1.99"
    "/home/kathleen/humanoid_robotics/project/fetch_ws/src/pcl/release/lib/libpcl_octree.so.1.8"
    "/home/kathleen/humanoid_robotics/project/fetch_ws/src/pcl/release/lib/libpcl_octree.so"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libpcl_octree.so.1.8.1.99"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libpcl_octree.so.1.8"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libpcl_octree.so"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHANGE
           FILE "${file}"
           OLD_RPATH "/home/kathleen/humanoid_robotics/project/fetch_ws/src/pcl/release/lib:"
           NEW_RPATH "/usr/lib")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/usr/bin/strip" "${file}")
      endif()
    endif()
  endforeach()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "pcl_octree")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/kathleen/humanoid_robotics/project/fetch_ws/src/pcl/release/octree/pcl_octree-1.8.pc")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "pcl_octree")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/pcl-1.8/pcl/octree" TYPE FILE FILES
    "/home/kathleen/humanoid_robotics/project/fetch_ws/src/pcl/octree/include/pcl/octree/boost.h"
    "/home/kathleen/humanoid_robotics/project/fetch_ws/src/pcl/octree/include/pcl/octree/octree_base.h"
    "/home/kathleen/humanoid_robotics/project/fetch_ws/src/pcl/octree/include/pcl/octree/octree_container.h"
    "/home/kathleen/humanoid_robotics/project/fetch_ws/src/pcl/octree/include/pcl/octree/octree_impl.h"
    "/home/kathleen/humanoid_robotics/project/fetch_ws/src/pcl/octree/include/pcl/octree/octree_nodes.h"
    "/home/kathleen/humanoid_robotics/project/fetch_ws/src/pcl/octree/include/pcl/octree/octree_key.h"
    "/home/kathleen/humanoid_robotics/project/fetch_ws/src/pcl/octree/include/pcl/octree/octree_pointcloud_density.h"
    "/home/kathleen/humanoid_robotics/project/fetch_ws/src/pcl/octree/include/pcl/octree/octree_pointcloud_occupancy.h"
    "/home/kathleen/humanoid_robotics/project/fetch_ws/src/pcl/octree/include/pcl/octree/octree_pointcloud_singlepoint.h"
    "/home/kathleen/humanoid_robotics/project/fetch_ws/src/pcl/octree/include/pcl/octree/octree_pointcloud_pointvector.h"
    "/home/kathleen/humanoid_robotics/project/fetch_ws/src/pcl/octree/include/pcl/octree/octree_pointcloud_changedetector.h"
    "/home/kathleen/humanoid_robotics/project/fetch_ws/src/pcl/octree/include/pcl/octree/octree_pointcloud_voxelcentroid.h"
    "/home/kathleen/humanoid_robotics/project/fetch_ws/src/pcl/octree/include/pcl/octree/octree_pointcloud.h"
    "/home/kathleen/humanoid_robotics/project/fetch_ws/src/pcl/octree/include/pcl/octree/octree_iterator.h"
    "/home/kathleen/humanoid_robotics/project/fetch_ws/src/pcl/octree/include/pcl/octree/octree_search.h"
    "/home/kathleen/humanoid_robotics/project/fetch_ws/src/pcl/octree/include/pcl/octree/octree.h"
    "/home/kathleen/humanoid_robotics/project/fetch_ws/src/pcl/octree/include/pcl/octree/octree2buf_base.h"
    "/home/kathleen/humanoid_robotics/project/fetch_ws/src/pcl/octree/include/pcl/octree/octree_pointcloud_adjacency.h"
    "/home/kathleen/humanoid_robotics/project/fetch_ws/src/pcl/octree/include/pcl/octree/octree_pointcloud_adjacency_container.h"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "pcl_octree")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/pcl-1.8/pcl/octree/impl" TYPE FILE FILES
    "/home/kathleen/humanoid_robotics/project/fetch_ws/src/pcl/octree/include/pcl/octree/impl/octree_base.hpp"
    "/home/kathleen/humanoid_robotics/project/fetch_ws/src/pcl/octree/include/pcl/octree/impl/octree_pointcloud.hpp"
    "/home/kathleen/humanoid_robotics/project/fetch_ws/src/pcl/octree/include/pcl/octree/impl/octree2buf_base.hpp"
    "/home/kathleen/humanoid_robotics/project/fetch_ws/src/pcl/octree/include/pcl/octree/impl/octree_iterator.hpp"
    "/home/kathleen/humanoid_robotics/project/fetch_ws/src/pcl/octree/include/pcl/octree/impl/octree_search.hpp"
    "/home/kathleen/humanoid_robotics/project/fetch_ws/src/pcl/octree/include/pcl/octree/impl/octree_pointcloud_voxelcentroid.hpp"
    "/home/kathleen/humanoid_robotics/project/fetch_ws/src/pcl/octree/include/pcl/octree/impl/octree_pointcloud_adjacency.hpp"
    )
endif()

