cmake_minimum_required(VERSION 3.6)
project(protocol_interface_CommandPattern)


add_subdirectory(src)

add_executable(utInterface ${PROJECT_SOURCE_DIR}/ut/utProtocolInterface.cpp ${PROJECT_SOURCE_DIR}/ut/utProtocol.cpp ${PROJECT_SOURCE_DIR}/ut/utProtocolType.cpp)

set(CMAKE_LIBRARY_PATH ${PROJECT_SOURCE_DIR}/build/lib)
message(STATUS "CMAKE_LIBRARY_PATH = " ${CMAKE_LIBRARY_PATH})
target_link_libraries(utInterface ${CMAKE_LIBRARY_PATH}/libgtest_main.a ${CMAKE_LIBRARY_PATH}/libgtest.a ${CMAKE_LIBRARY_PATH}/libInterface.a)