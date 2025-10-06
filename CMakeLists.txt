cmake_minimum_required(VERSION 3.22)
project(Code VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Connecting used libraries
find_package(GTest REQUIRED)

# Recursively getting all header files
file(
    GLOB_RECURSE
    CODE_HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.hpp
)
# Recursively getting all header files
file(
    GLOB_RECURSE
    CODE_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
)

# Add executable
add_executable(${CMAKE_PROJECT_NAME} ${CODE_HEADERS} ${CODE_SOURCES})

# Add include directories
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE
    src
)

# Add project options
target_compile_options(${CMAKE_PROJECT_NAME} PRIVATE
)

# Add project symbols (macros)
target_compile_definitions(${CMAKE_PROJECT_NAME} PRIVATE
)

# Link libraries
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE
    GTest::GTest
)