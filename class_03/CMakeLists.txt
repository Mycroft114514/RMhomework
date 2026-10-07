cmake_minimum_required(VERSION 3.16)
project(class_03 LANGUAGES CXX)

add_executable(class_03 
    main.cpp 
    src/MarkerManager.cpp
)
target_include_directories(class_03 PRIVATE include)
target_compile_features(class_03 PRIVATE cxx_std_17)