cmake_minimum_required(VERSION 3.23)
project(M32_Task_1)

set(CMAKE_CXX_STANDARD 14)

set(JSON_BuildTests OFF CACHE INTERNAL "")

add_subdirectory(nlohmann_json)

add_executable(M32_Task_1 main.cpp)

target_link_libraries(M32_Task_1 PRIVATE nlohmann_json::nlohmann_json)