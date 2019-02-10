cmake_minimum_required(VERSION 2.8) #Проверка версии CMake.

set(PROJECT_NAME 381706-1_Kornev_AllLabs) #Создаем обычную локальную переменную с именем проекта
project(${PROJECT_NAME}) # Название проекта

set(Stack Stack)
set(StackLib StackLib)
set(StackTest StackTest)

set(Queue Queue)
set(QueueLib QueueLib)
set(QueueTest QueueTest)

set(Vector Vector)
set(VectorLib VectorLib)
set(VectorTest VectorTest)

set(Matrix Matrix)
set(MatrixLib MatrixLib)
set(MatrixTest MatrixTest)

set(MyExceptionLib MyExceptionLib)


set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configs" FORCE) #Создается переменная CMAKE_CONFIGURATION_TYPES со значением "Debug;Release" и меткой/разделом Configs, переменная сохраниется в специальном файле доступном из всех файлов,
if(NOT CMAKE_BUILD_TYPE) # проверка имеющихся у компилятора вариантов сборки
  set(CMAKE_BUILD_TYPE Release) #Если нет то устанавливаем Release
endif()

file(GLOB hdrs "*.h*") #Добавляем в переменную hdrs все файлы с расширением .h
file(GLOB srcs "*.cpp") #Добавляем в переменную srcs все файлы с расширением .cpp

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/gtest)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/StackLib)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/QueueLib)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/VectorLib)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/MatrixLib)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/MyExceptionLib)

add_subdirectory(Stack)
add_subdirectory(StackLib)
add_subdirectory(StackTest)

add_subdirectory(Queue)
add_subdirectory(QueueLib)
add_subdirectory(QueueTest)

add_subdirectory(Matrix)
add_subdirectory(MatrixLib)
add_subdirectory(MatrixTest)

add_subdirectory(Vector)
add_subdirectory(VectorLib)
add_subdirectory(VectorTest)

add_subdirectory(gtest)
add_subdirectory(MyExceptionLib)
