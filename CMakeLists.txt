cmake_minimum_required(VERSION 2.8) 

set(PROJECT_NAME 381706-1_Kornev_AllLabs) 
project(${PROJECT_NAME}) 

set(Vector Vector)
set(VectorLib VectorLib)
set(VectorTest VectorTest)

set(Queue Queue)
set(QueueLib QueueLib)
set(QueueTest QueueTest)

set(ArrayList ArrayList)
set(ArrayListLib ArrayListLib)
set(ArrayListTest ArrayListTest)

set(StackList StackList)
set(StackListLib StackListLib)
set(StackListTest StackListTest)

set(List List)
set(ListLib ListLib)
set(ListTest ListTest)

set(MultiStack MultiStack)
set(MultiStackLib MultiStackLib)
set(MultiStackTest MultiStackTest)

set(Stack Stack)
set(StackLib StackLib)
set(StackTest StackTest)

set(Matrix Matrix)
set(MatrixLib MatrixLib)
set(MatrixTest MatrixTest)

set(Polinomial Polinomial)
set(PolinomialLib PolinomialLib)
set(PolinomialTest PolinomialTest)

set(RPN RPN)
set(RPNLib RPNLib)
set(RPNTest RPNTest)

set(Text Text)
set(TextLib TextLib)
set(TextTest TextTest)

set(MyExceptionLib MyExceptionLib)

set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configs" FORCE) 
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release) 
endif()

file(GLOB hdrs "*.h*") 
file(GLOB srcs "*.cpp") 
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/gtest)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/MyExceptionLib)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/VectorLib)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/StackLib)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/QueueLib)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/MatrixLib)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/PolinomialLib)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/MultiStackLib)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/StackListLib)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/ArrayListLib)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/ListLib)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/RPNLib)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/TextLib)

add_subdirectory(Vector)
add_subdirectory(VectorLib)
add_subdirectory(VectorTest)

add_subdirectory(ArrayList)
add_subdirectory(ArrayListLib)
add_subdirectory(ArrayListTest)

add_subdirectory(List)
add_subdirectory(ListLib)
add_subdirectory(ListTest)

add_subdirectory(StackList)
add_subdirectory(StackListLib)
add_subdirectory(StackListTest)

add_subdirectory(MultiStack)
add_subdirectory(MultiStackLib)
add_subdirectory(MultiStackTest)

add_subdirectory(Stack)
add_subdirectory(StackLib)
add_subdirectory(StackTest)

add_subdirectory(Polinomial)
add_subdirectory(PolinomialLib)
add_subdirectory(PolinomialTest)

add_subdirectory(Queue)
add_subdirectory(QueueLib)
add_subdirectory(QueueTest)

add_subdirectory(Matrix)
add_subdirectory(MatrixLib)
add_subdirectory(MatrixTest)

add_subdirectory(RPN)
add_subdirectory(RPNLib)
add_subdirectory(RPNTest)

add_subdirectory(Text)
add_subdirectory(TextLib)
add_subdirectory(TextTest)

add_subdirectory(gtest)
add_subdirectory(MyExceptionLib)
