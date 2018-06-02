cmake_minimum_required(VERSION 3.6)

message(STATUS "PROJECT_SOURCE_DIR = " ${PROJECT_SOURCE_DIR})
message(STATUS "CMAKE_CURRENT_SOURCE_DIR = " ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(ProtocolInterface main.cpp)

include_directories(${PROJECT_SOURCE_DIR}/include)

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build/lib)
add_library(Interface STATIC ProtocolType.cpp Protocol.cpp Interface.cpp)

set(CMAKE_LIBRARY_PATH ${LIBRARY_OUTPUT_PATH})
find_library(lib libInterface.a)
if(lib)
message(STATUS "find the lib path = " ${LIBRARY_OUTPUT_PATH})
elseif()
message(STATUS "no find lib")
endif()
set(CMAKE_ALLOW_LOOSE_LOOP_CONSTRUCTS ON)

target_link_libraries(ProtocolInterface ${LIBRARY_OUTPUT_PATH}/libInterface.a)