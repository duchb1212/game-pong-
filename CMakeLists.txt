cmake_minimum_required(VERSION 3.10)
project(Pong CXX)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} ${CMAKE_SOURCE_DIR}/include)


file(GLOB SOURCES src/*.cpp)


add_executable(pong ${SOURCES})

target_link_libraries(pong ${SDL2_LIBRARIES})