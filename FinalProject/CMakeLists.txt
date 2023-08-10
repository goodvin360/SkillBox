cmake_minimum_required(VERSION 3.23)
project(FinalProject)

set(CMAKE_CXX_STANDARD 17)

set(JSON_BuildTests OFF CACHE INTERNAL "")

add_subdirectory(nlohmann_json)
add_subdirectory(Google_tests)

include_directories(${PROJECT_SOURCE_DIR}/include)

file(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cpp)
file(GLOB headers ${PROJECT_SOURCE_DIR}/include/*.h)

add_executable(FinalProject main.cpp ${sources} ${headers})
target_link_libraries(FinalProject PRIVATE nlohmann_json::nlohmann_json)
