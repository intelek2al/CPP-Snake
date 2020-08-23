cmake_minimum_required(VERSION 3.1)

project(src LANGUAGES CXX)
add_library(src CMakeLists.txt Food.cpp Food.h Includes.h Snake.cpp Snake.h SnakeBlocks.cpp SnakeBlocks.h)
