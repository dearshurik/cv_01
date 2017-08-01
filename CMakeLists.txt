cmake_minimum_required(VERSION 3.7)
project(cv_01)

set(CMAKE_CXX_STANDARD 14)

find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

set(SOURCE_FILES main.cpp videocap.h videoengine.h videopluginbase.h videorender.h threadsafe_queue.h)

add_executable(cv_01 ${SOURCE_FILES})
target_link_libraries(cv_01 ${OpenCV_LIBS})