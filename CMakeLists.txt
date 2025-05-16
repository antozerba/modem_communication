cmake_minimum_required(VERSION 3.8)
project(modem_communication)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rosidl_default_generators REQUIRED)

add_executable(desert_publisher src/desert_publisher.cpp)
add_executable(desert_sub src/desert_listener.cpp)
add_executable(prova src/prova.cpp)

ament_target_dependencies(desert_publisher rclcpp std_msgs)
ament_target_dependencies(desert_sub rclcpp std_msgs)
ament_target_dependencies(prova rclcpp std_msgs)

rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/Desert.msg"
  "msg/MonoIR.msg"
  "msg/Odometry.msg"
  "msg/StereoIR.msg"
)

install(TARGETS 
  prova
  desert_publisher
  desert_sub
  DESTINATION lib/${PROJECT_NAME}
)


ament_package()
