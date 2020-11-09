cmake_minimum_required(VERSION 2.6)  # CMake version check
project(practica2)               # Create project

# Add main.cpp file of project root directory as source file
set(SOURCE_FILES 
	src/main.cc 
	src/classTime/classTime.cc
	src/funciones/funciones.cc
)

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(exponenciacion ${SOURCE_FILES})
