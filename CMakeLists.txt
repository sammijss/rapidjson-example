cmake_minimum_required(VERSION 2.0)

#set(CMAKE_BUILD_TYPE build)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_BUILD_TYPE}/bin)

add_executable(
    example-json-create
    src/example-json-create.cpp
)

add_executable(
    example-json-parser
    src/example-json-parser.cpp
)
