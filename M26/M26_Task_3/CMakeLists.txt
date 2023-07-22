cmake_minimum_required(VERSION 3.23)
project(M26_Task_3)

set(CMAKE_CXX_STANDARD 14)

include_directories(${PROJECT_SOURCE_DIR}/include)

file(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cpp)
file(GLOB headers ${PROJECT_SOURCE_DIR}/include/*.h)

add_executable(M26_Task_3 main.cpp ${sources} ${headers})
