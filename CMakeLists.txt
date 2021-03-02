cmake_minimum_required(VERSION 3.10)
project(leetcode)
#set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(BUILD_DEPS "YES" CACHE BOOL "If YES, will install dependencies into sandbox.  Automatically reset to NO after dependencies are installed.")
set(PROJECT_OUTPUT_DIR  ${PROJECT_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_OUTPUT_DIR}/bin)  ## mkdir bin
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_OUTPUT_DIR}/lib)  ## mkdir lib
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_OUTPUT_DIR}/lib)
# OpenCV 
#find_package(OpenCV REQUIRED)

include_directories(include ${OpenCV_INCLUDE_DIRS}/include)

# easy
add_executable(${PROJECT_NAME} src/easy/7_Reverse_Integer.cpp)

# medium
#add_executable(${PROJECT_NAME} src/medium/2_Reverse_Integer.cpp)

# hard
#add_executable(${PROJECT_NAME} src/hard/4_Reverse_Integer.cpp)

target_link_libraries(${PROJECT_NAME})
