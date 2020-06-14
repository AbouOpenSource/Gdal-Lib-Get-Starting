cmake_minimum_required(VERSION 3.15)
project(testGdal)

set(CMAKE_CXX_STANDARD 20)

#add_executable(testGdal main.cpp Main.cpp)
add_executable(testGdal Main.cpp)

target_link_libraries(testGdal gdal)