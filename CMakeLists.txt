cmake_minimum_required(VERSION 3.22)
project(Code VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(GTest REQUIRED)

# Source library ----------------------------------------------------------------------->
set(SOURCE_LIBRARY_NAME CodeSource)

# Add library
add_library(${SOURCE_LIBRARY_NAME} STATIC)

# Add source directories
target_include_directories(${SOURCE_LIBRARY_NAME} PUBLIC
    src
)

# Add header files
target_sources(${SOURCE_LIBRARY_NAME} PUBLIC
    src/template.hpp

    src/general/sort/insert.hpp
    src/general/sort/merge.hpp
)

# Add implemetation files
target_sources(${SOURCE_LIBRARY_NAME} PRIVATE
    src/template.cpp

    src/general/sort/insert.cpp
    src/general/sort/merge.cpp
)

# Main ---------------------------------------------------------------------------------->

# Add executable
add_executable(${CMAKE_PROJECT_NAME})

# Add source directories
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE
    src
)

# Add implemetation files
target_sources(${CMAKE_PROJECT_NAME} PRIVATE
    src/main.cpp
)

# Add project symbols (macros)
target_compile_definitions(${CMAKE_PROJECT_NAME} PRIVATE
    # Add user defined symbols
)

# Link libraries
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE
    ${SOURCE_LIBRARY_NAME}
)

# Tests ---------------------------------------------------------------------------------->

set(TEST_PROJECT_NAME CodeTest)

# Add test executable
add_executable(${TEST_PROJECT_NAME})

# Add test directories
target_include_directories(${TEST_PROJECT_NAME} PRIVATE
    tests
)

# Add  sources
target_sources(${TEST_PROJECT_NAME} PRIVATE
    tests/general/sort/merge_test.cpp
)

# Add project symbols (macros)
target_compile_definitions(${TEST_PROJECT_NAME} PRIVATE
    # Add user defined symbols
)

# Link test target with libraries
target_link_libraries(${TEST_PROJECT_NAME} PRIVATE
    ${SOURCE_LIBRARY_NAME}
    GTest::GTest
    GTest::Main
)

# Testing
enable_testing()
add_test(NAME Merge COMMAND ${TEST_PROJECT_NAME})