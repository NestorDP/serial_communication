cmake_minimum_required(VERSION 2.8.3)
project(serial_communication)

add_definitions(-std=c++11)

find_package(catkin REQUIRED COMPONENTS roscpp)
find_package(Boost REQUIRED COMPONENTS system)

add_action_files(
    DIRECTORY action
    FILES ScanControl.action
)

generate_messages(
  DEPENDENCIES
  std_msgs  # Or other packages containing msgs
)

catkin_package(
 INCLUDE_DIRS include
)

include_directories(
include
${catkin_INCLUDE_DIRS}
${Boost_INCLUDE_DIRS}
)

add_executable(${PROJECT_NAME}_node src/serial_communication.cpp src/main.cpp)

add_dependencies(${PROJECT_NAME}_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

target_link_libraries(${PROJECT_NAME}_node
  ${catkin_LIBRARIES}
)

