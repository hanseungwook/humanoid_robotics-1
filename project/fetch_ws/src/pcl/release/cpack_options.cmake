set(CPACK_PACKAGE_NAME "PCL")
set(CPACK_PACKAGE_VENDOR "PointClouds.org")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Point Cloud Library (PCL)")
set(CPACK_PACKAGE_INSTALL_DIRECTORY "PCL 1.8.1-dev")
set(CPACK_RESOURCE_FILE_LICENSE "/home/kathleen/humanoid_robotics/project/fetch_ws/src/pcl/LICENSE.txt")
set(CPACK_RESOURCE_FILE_README "/home/kathleen/humanoid_robotics/project/fetch_ws/src/pcl/AUTHORS.txt")

set(CPACK_COMPONENT_PCL_COMMON_DISPLAY_NAME "common")
set(CPACK_COMPONENT_PCL_COMMON_DESCRIPTION "Point cloud common library")
set(CPACK_COMPONENT_PCL_COMMON_DEPENDS )
set(CPACK_COMPONENT_PCL_COMMON_GROUP "PCL")
set(CPACK_COMPONENT_PCL_OCTREE_DISPLAY_NAME "octree")
set(CPACK_COMPONENT_PCL_OCTREE_DESCRIPTION "Point cloud octree library")
set(CPACK_COMPONENT_PCL_OCTREE_DEPENDS  pcl_common)
set(CPACK_COMPONENT_PCL_OCTREE_GROUP "PCL")
set(CPACK_COMPONENT_PCL_IO_DISPLAY_NAME "io")
set(CPACK_COMPONENT_PCL_IO_DESCRIPTION "Point cloud IO library")
set(CPACK_COMPONENT_PCL_IO_DEPENDS  pcl_common pcl_octree)
set(CPACK_COMPONENT_PCL_IO_GROUP "PCL")
set(CPACK_COMPONENT_PCL_KDTREE_DISPLAY_NAME "kdtree")
set(CPACK_COMPONENT_PCL_KDTREE_DESCRIPTION "Point cloud kd-tree library")
set(CPACK_COMPONENT_PCL_KDTREE_DEPENDS  pcl_common)
set(CPACK_COMPONENT_PCL_KDTREE_GROUP "PCL")
set(CPACK_COMPONENT_PCL_GEOMETRY_DISPLAY_NAME "geometry")
set(CPACK_COMPONENT_PCL_GEOMETRY_DESCRIPTION "Point cloud geometry library")
set(CPACK_COMPONENT_PCL_GEOMETRY_DEPENDS  pcl_common)
set(CPACK_COMPONENT_PCL_GEOMETRY_GROUP "PCL")
set(CPACK_COMPONENT_PCL_SEARCH_DISPLAY_NAME "search")
set(CPACK_COMPONENT_PCL_SEARCH_DESCRIPTION "Point cloud generic search library")
set(CPACK_COMPONENT_PCL_SEARCH_DEPENDS  pcl_common pcl_kdtree pcl_octree)
set(CPACK_COMPONENT_PCL_SEARCH_GROUP "PCL")
set(CPACK_COMPONENT_PCL_VISUALIZATION_DISPLAY_NAME "visualization")
set(CPACK_COMPONENT_PCL_VISUALIZATION_DESCRIPTION "Point cloud visualization library")
set(CPACK_COMPONENT_PCL_VISUALIZATION_DEPENDS  pcl_common pcl_io pcl_kdtree pcl_geometry pcl_search pcl_octree)
set(CPACK_COMPONENT_PCL_VISUALIZATION_GROUP "PCL")
set(CPACK_COMPONENT_PCL_SAMPLE_CONSENSUS_DISPLAY_NAME "sample_consensus")
set(CPACK_COMPONENT_PCL_SAMPLE_CONSENSUS_DESCRIPTION "Point cloud sample consensus library")
set(CPACK_COMPONENT_PCL_SAMPLE_CONSENSUS_DEPENDS  pcl_common pcl_search)
set(CPACK_COMPONENT_PCL_SAMPLE_CONSENSUS_GROUP "PCL")
set(CPACK_COMPONENT_PCL_FILTERS_DISPLAY_NAME "filters")
set(CPACK_COMPONENT_PCL_FILTERS_DESCRIPTION "Point cloud filters library")
set(CPACK_COMPONENT_PCL_FILTERS_DEPENDS  pcl_common pcl_sample_consensus pcl_search pcl_kdtree pcl_octree)
set(CPACK_COMPONENT_PCL_FILTERS_GROUP "PCL")
set(CPACK_COMPONENT_PCL_2D_DISPLAY_NAME "2d")
set(CPACK_COMPONENT_PCL_2D_DESCRIPTION "Point cloud 2d")
set(CPACK_COMPONENT_PCL_2D_DEPENDS  pcl_common pcl_filters)
set(CPACK_COMPONENT_PCL_2D_GROUP "PCL")
set(CPACK_COMPONENT_PCL_FEATURES_DISPLAY_NAME "features")
set(CPACK_COMPONENT_PCL_FEATURES_DESCRIPTION "Point cloud features library")
set(CPACK_COMPONENT_PCL_FEATURES_DEPENDS  pcl_common pcl_search pcl_kdtree pcl_octree pcl_filters pcl_2d)
set(CPACK_COMPONENT_PCL_FEATURES_GROUP "PCL")
set(CPACK_COMPONENT_PCL_ML_DISPLAY_NAME "ml")
set(CPACK_COMPONENT_PCL_ML_DESCRIPTION "Point cloud machine learning library")
set(CPACK_COMPONENT_PCL_ML_DEPENDS  pcl_common)
set(CPACK_COMPONENT_PCL_ML_GROUP "PCL")
set(CPACK_COMPONENT_PCL_SEGMENTATION_DISPLAY_NAME "segmentation")
set(CPACK_COMPONENT_PCL_SEGMENTATION_DESCRIPTION "Point cloud segmentation library")
set(CPACK_COMPONENT_PCL_SEGMENTATION_DEPENDS  pcl_common pcl_geometry pcl_search pcl_sample_consensus pcl_kdtree pcl_octree pcl_features pcl_filters pcl_ml)
set(CPACK_COMPONENT_PCL_SEGMENTATION_GROUP "PCL")
set(CPACK_COMPONENT_PCL_PEOPLE_DISPLAY_NAME "people")
set(CPACK_COMPONENT_PCL_PEOPLE_DESCRIPTION "Point cloud people library")
set(CPACK_COMPONENT_PCL_PEOPLE_DEPENDS  pcl_common pcl_kdtree pcl_search pcl_features pcl_sample_consensus pcl_filters pcl_io pcl_visualization pcl_geometry pcl_segmentation pcl_octree)
set(CPACK_COMPONENT_PCL_PEOPLE_GROUP "PCL")
set(CPACK_COMPONENT_PCL_TRACKING_DISPLAY_NAME "tracking")
set(CPACK_COMPONENT_PCL_TRACKING_DESCRIPTION "Point cloud tracking library")
set(CPACK_COMPONENT_PCL_TRACKING_DEPENDS  pcl_common pcl_search pcl_kdtree pcl_filters pcl_octree)
set(CPACK_COMPONENT_PCL_TRACKING_GROUP "PCL")
set(CPACK_COMPONENT_PCL_STEREO_DISPLAY_NAME "stereo")
set(CPACK_COMPONENT_PCL_STEREO_DESCRIPTION "Point cloud stereo library")
set(CPACK_COMPONENT_PCL_STEREO_DEPENDS  pcl_common pcl_io)
set(CPACK_COMPONENT_PCL_STEREO_GROUP "PCL")
set(CPACK_COMPONENT_PCL_SURFACE_DISPLAY_NAME "surface")
set(CPACK_COMPONENT_PCL_SURFACE_DESCRIPTION "Point cloud surface library")
set(CPACK_COMPONENT_PCL_SURFACE_DEPENDS  pcl_common pcl_search pcl_kdtree pcl_octree)
set(CPACK_COMPONENT_PCL_SURFACE_GROUP "PCL")
set(CPACK_COMPONENT_PCL_REGISTRATION_DISPLAY_NAME "registration")
set(CPACK_COMPONENT_PCL_REGISTRATION_DESCRIPTION "Point cloud registration library")
set(CPACK_COMPONENT_PCL_REGISTRATION_DEPENDS  pcl_common pcl_octree pcl_kdtree pcl_search pcl_sample_consensus pcl_features pcl_filters)
set(CPACK_COMPONENT_PCL_REGISTRATION_GROUP "PCL")
set(CPACK_COMPONENT_PCL_RECOGNITION_DISPLAY_NAME "recognition")
set(CPACK_COMPONENT_PCL_RECOGNITION_DESCRIPTION "Point cloud recognition library")
set(CPACK_COMPONENT_PCL_RECOGNITION_DEPENDS  pcl_common pcl_io pcl_search pcl_kdtree pcl_octree pcl_features pcl_filters pcl_registration pcl_sample_consensus pcl_ml)
set(CPACK_COMPONENT_PCL_RECOGNITION_GROUP "PCL")
set(CPACK_COMPONENT_PCL_KEYPOINTS_DISPLAY_NAME "keypoints")
set(CPACK_COMPONENT_PCL_KEYPOINTS_DESCRIPTION "Point cloud keypoints library")
set(CPACK_COMPONENT_PCL_KEYPOINTS_DEPENDS  pcl_common pcl_search pcl_kdtree pcl_octree pcl_features pcl_filters)
set(CPACK_COMPONENT_PCL_KEYPOINTS_GROUP "PCL")
set(CPACK_COMPONENT_PCL_TOOLS_DISPLAY_NAME "tools")
set(CPACK_COMPONENT_PCL_TOOLS_DESCRIPTION "Useful PCL-based command line tools")
set(CPACK_COMPONENT_PCL_TOOLS_DEPENDS  pcl_visualization)
set(CPACK_COMPONENT_PCL_TOOLS_GROUP "PCL")
set(CPACK_COMPONENT_PCL_APPS_DISPLAY_NAME "apps")
set(CPACK_COMPONENT_PCL_APPS_DESCRIPTION "Application examples/samples that show how PCL works")
set(CPACK_COMPONENT_PCL_APPS_DEPENDS  pcl_common pcl_geometry pcl_io pcl_filters pcl_sample_consensus pcl_segmentation pcl_visualization pcl_kdtree pcl_features pcl_surface pcl_octree pcl_registration pcl_keypoints pcl_tracking pcl_search pcl_recognition pcl_ml pcl_stereo pcl_2d)
set(CPACK_COMPONENT_PCL_APPS_GROUP "PCL")
set(CPACK_COMPONENT_PCL_OUTOFCORE_DISPLAY_NAME "outofcore")
set(CPACK_COMPONENT_PCL_OUTOFCORE_DESCRIPTION "Point cloud outofcore library")
set(CPACK_COMPONENT_PCL_OUTOFCORE_DEPENDS  pcl_common pcl_io pcl_filters pcl_octree pcl_visualization)
set(CPACK_COMPONENT_PCL_OUTOFCORE_GROUP "PCL")

set(CPACK_COMPONENT_PCLCONFIG_GROUP "PCL")

set(CPACK_COMPONENT_PCLCONFIG_DISPLAY_NAME "PCLConfig")

set(CPACK_COMPONENT_PCLCONFIG_DESCRIPTION "Helper cmake configuration scripts used by find_package(PCL)")

set(CPACK_COMPONENTS_ALL pcl_common pcl_octree pcl_io pcl_kdtree pcl_geometry pcl_search pcl_visualization pcl_sample_consensus pcl_filters pcl_2d pcl_features pcl_ml pcl_segmentation pcl_people pcl_tracking pcl_stereo pcl_surface pcl_registration pcl_recognition pcl_keypoints pcl_tools pcl_apps pcl_outofcore pclconfig)


IF ((WIN32 OR UNIX) AND (CPACK_GENERATOR STREQUAL "NSIS"))
    set(CPACK_NSIS_DISPLAY_NAME "PCL-1.8.1-dev")
    set(CPACK_NSIS_MUI_ICON "/home/kathleen/humanoid_robotics/project/fetch_ws/src/pcl/cmake/images/pcl.ico")
    set(CPACK_NSIS_MUI_UNIICON "/home/kathleen/humanoid_robotics/project/fetch_ws/src/pcl/cmake/images/pcl.ico")
    set(CPACK_NSIS_HELP_LINK "http://www.pointclouds.org")
    set(CPACK_NSIS_URL_INFO_ABOUT "http://www.pointclouds.org")
    set(CPACK_NSIS_MODIFY_PATH ON)
    set(CPACK_PACKAGE_EXECUTABLES )
    set(CPACK_NSIS_MENU_LINKS 
            "share/doc/pcl-1.8/tutorials/html/index.html" "Tutorials"
            "share/doc/pcl-1.8/tutorials/html/sources" "Tutorials sources"
            "share/doc/pcl-1.8/html/pcl-1.8.chm" "Documentation"
            "http://www.pointclouds.org" "PCL Website")
    #set(CPACK_NSIS_MENU_LINKS "share/doc/PCL/user_guide.pdf" "User's guide")
    #set(CPACK_NSIS_MENU_LINKS "share/doc/PCL/developer_guide.pdf" "Developer's guide")
    if(WIN32 AND NOT UNIX)
      # There is a bug in NSI that does not handle full unix paths properly. Make
      # sure there is at least one set of four (4) backlasshes.
      set(CPACK_PACKAGE_ICON "/home/kathleen/humanoid_robotics/project/fetch_ws/src/pcl/cmake/images\\\\pcl_horz_large_pos.bmp")
    else(WIN32 AND NOT UNIX)
      set(CPACK_PACKAGE_ICON "/home/kathleen/humanoid_robotics/project/fetch_ws/src/pcl/cmake/images/pcl_horz_large_pos.bmp")
    endif(WIN32 AND NOT UNIX)
ENDIF ()

IF (UNIX AND ((CPACK_GENERATOR STREQUAL "DEB") OR (CPACK_GENERATOR STREQUAL "RPM")))
    # define stuff for the DEB/RPM packages
    set(CPACK_PACKAGE_CONTACT "pcl-developers@pointclouds.org")
ENDIF ()

IF (UNIX AND (CPACK_GENERATOR STREQUAL "DEB"))
  SET(CPACK_DEBIAN_PACKAGE_SHLIBDEPS ON)
ENDIF ()

IF (APPLE AND (CPACK_GENERATOR STREQUAL "PackageMaker"))
    # define stuff for the PackageMaker packages
    set(CPACK_OSX_PACKAGE_VERSION 10.5)
    set(CPACK_PACKAGE_CONTACT "pcl-developers@pointclouds.org")
    set(CPACK_SET_DESTDIR ON)
    set(CPACK_PACKAGING_INSTALL_PREFIX /usr/local)
ENDIF ()
