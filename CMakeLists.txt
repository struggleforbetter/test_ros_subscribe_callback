cmake_minimum_required( VERSION 2.8 )
project( test )

set( CMAKE_BUILD_TYPE "Release" )
set( CMAKE_CXX_FLAGS "-std=c++11 -O3" )

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
)

catkin_package(
  
)


include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable( main src/main.cpp )

target_link_libraries(main
    ${catkin_LIBRARIES}
)

