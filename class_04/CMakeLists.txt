cmake_minimum_required(VERSION 3.16)
project(class_04 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

if(MSVC)
    add_compile_options(/utf-8)
endif()

find_package(OpenCV 4 REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(class_04 main.cpp)
target_link_libraries(class_04 PRIVATE ${OpenCV_LIBS})