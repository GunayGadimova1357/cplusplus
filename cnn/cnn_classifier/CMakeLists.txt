cmake_minimum_required(VERSION 3.29)
project(cnn_classifier)

set(CMAKE_CXX_STANDARD 20)

set(OpenCV_DIR "/usr/local/opt/opencv/share/opencv4")

find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(cnn_classifier main.cpp)

target_link_libraries(cnn_classifier ${OpenCV_LIBS})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")