cmake_minimum_required(VERSION 3.22)
project(Code VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(GTest REQUIRED)

# Main ---------------------------------------------------------------------------------->

# Add main executable
add_executable(${CMAKE_PROJECT_NAME})

# Add main directories
target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC
    src
)

# Add main header-files
target_sources(${CMAKE_PROJECT_NAME} PUBLIC
    src/template.hpp

    src/general/sort/insert.hpp
    src/general/sort/merge.hpp
)


# Add main source-files
target_sources(${CMAKE_PROJECT_NAME} PRIVATE
    src/main.cpp
    src/template.cpp

    src/general/sort/insert.cpp
    src/general/sort/merge.cpp
)

# Add project symbols (macros)
target_compile_definitions(${CMAKE_PROJECT_NAME} PRIVATE
    # Add user defined symbols
)

# Link main target with libraries
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE
)

# Tests ---------------------------------------------------------------------------------->

set(TEST_PROJECT_NAME CodeTests)

# Add test executable
add_executable(${TEST_PROJECT_NAME})

# Add test directories
target_include_directories(${TEST_PROJECT_NAME} PUBLIC
    tests
    src
)

# Add test sources
target_sources(${TEST_PROJECT_NAME} PRIVATE
    tests/general/sort/merge.cpp

    src/general/sort/merge.hpp
    src/general/sort/merge.cpp
)

# Add project symbols (macros)
target_compile_definitions(${TEST_PROJECT_NAME} PRIVATE
    # Add user defined symbols
)

# Link test target with libraries
target_link_libraries(${TEST_PROJECT_NAME} PRIVATE
    GTest::GTest
    GTest::Main
)

# Включение тестирования
enable_testing()
add_test(NAME Merge COMMAND ${TEST_PROJECT_NAME})