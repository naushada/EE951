cmake_minimum_required(VERSION 3.16.3)
project(EE951)
find_package(GTest REQUIRED)


include_directories(../inc)
include_directories(test)

#Adding Complier flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++2a -g -Wall -Wextra")

#However, the file(GLOB...) allows for wildcard additions:
file(GLOB SOURCES "*.cpp"  
                    "../src/vectors.cpp")

enable_testing()

add_executable(EE951_test ${SOURCES})
target_link_libraries(EE951_test gtest_main)

target_link_libraries(EE951_test gtest)
target_link_libraries(EE951_test pthread)
target_link_libraries(EE951_test z)

add_test(EE951_gtests EE951_test)
gtest_discover_tests(EE951_test)
