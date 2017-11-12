cmake_minimum_required(VERSION 3.8)
project(08_DualCycleLinkedList)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        DualCycleLinkedList-main.c
        DualCycleLinkedList.c
        DualCycleLinkedList.h)

add_executable(08_DualCycleLinkedList ${SOURCE_FILES})