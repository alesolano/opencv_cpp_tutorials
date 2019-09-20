#!/bin/bash

if [ $# -eq 0 ]
  then
    echo "ERROR: Unable to create a project. Please provide a project name"
    exit 1
fi

mkdir $1
mkdir $1/src $1/build $1/include

echo "cmake_minimum_required(VERSION 3.5.1)

set(CMAKE_CXX_STANDARD 14)

project($1)
file(GLOB SOURCES src/*.cpp)

add_executable(\${PROJECT_NAME} \${SOURCES})

#include_directories(include)
find_package( OpenCV REQUIRED )
target_link_libraries(\${PROJECT_NAME} \${OpenCV_LIBS} )
" >> $1/CMakeLists.txt

echo "#include <iostream>

int main()
{
    std::cout << \"Hello world!\" << std::endl;
    return 0;
}
" >> $1/src/main.cpp

echo "Project $1 created successfully"
