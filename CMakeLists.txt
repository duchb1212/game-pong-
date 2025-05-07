cmake_minimum_required(VERSION 3.10)
project(Pong CXX)

# Tìm SDL2
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} ${CMAKE_SOURCE_DIR}/include)

# Thêm các file nguồn
file(GLOB SOURCES src/*.cpp)

# Tạo file thực thi
add_executable(pong ${SOURCES})

# Liên kết với SDL2
target_link_libraries(pong ${SDL2_LIBRARIES})