cmake_minimum_required(VERSION 3.10)

project(laba13 C)

option(BUILD_SHARED_LIBS "shared lib(on/off)" OFF)

include_directories(include)

add_library(FootLib src/footballers.c)

add_executable(program src/main.c)

target_link_libraries(program FootLib)