cmake_minimum_required(VERSION 2.8) 

set(PROJECT_NAME 381706-1_Kornev_AllLabs) 
project(${PROJECT_NAME}) 

set(Stack Stack)
set(StackLib StackLib)
set(StackTest StackTest)

set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configs" FORCE)
if(NOT CMAKE_BUILD_TYPE) 
  set(CMAKE_BUILD_TYPE Release) 
endif()

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/gtest)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/StackLib)

add_subdirectory(gtest)
add_subdirectory(Stack)
add_subdirectory(StackLib)
add_subdirectory(StackTest)

file(GLOB hdrs "*.h*") 
file(GLOB srcs "*.cpp")
