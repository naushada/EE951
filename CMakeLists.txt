cmake_minimum_required(VERSION 3.16.3)
project(EE951 C CXX)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -g -Wall -Wextra -O0")
set(CMAKE_VERBOSE_MAKEFILE ON)
#set(CMAKE_C_COMPILER /usr/bin/gcc)
#set(CMAKE_CXX_COMPILER /usr/bin/g++)


# Include External cmake file
include_directories(inc)


#all files from src directory, the file(GLOB...) allows for wildcard additions:
file(GLOB SOURCES "*.cpp")

add_executable(EE951 ${SOURCES})
target_link_libraries(EE951 
                      pthread
                      ssl
                      crypto)

add_subdirectory(test)

install(TARGETS EE951
        CONFIGURATIONS Release
        RUNTIME DESTINATION /usr/local/bin
)
