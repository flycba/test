cmake_minimum_required(VERSION 3.6)
project(head)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        tests/newcunittest.c
        tests/newcunittest1.c
        tests/newcunittest2.c
        tests/newcunittest3.c
        tests/newsimpletest.c
        main.c
        stack.c
        stack.h)

add_executable(head ${SOURCE_FILES})