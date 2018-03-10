cmake_minimum_required(VERSION 2.8.3)
project(nodelet_tutorial)

## Find catkin and any catkin packages
find_package(catkin_simple REQUIRED)
catkin_simple(ALL_DEPS_REQUIRED)
set(CMAKE_BUILD_TYPE Release)

add_definitions(-std=c++11)

add_library(nodelet_tutorial
  src/talker.cpp
  src/listener.cpp
)
target_link_libraries(nodelet_tutorial ${catkin_LIBRARIES})

install(
  DIRECTORY include/${PROJECT_NAME}/
  DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
  FILES_MATCHING PATTERN "*.h"
)
cs_install()
cs_export()
