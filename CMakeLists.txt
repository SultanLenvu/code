cmake_minimum_required(VERSION 3.22)
project(Code VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(GTest REQUIRED)

# Main ---------------------------------------------------------------------------------->

# Add executable
add_executable(${CMAKE_PROJECT_NAME})

# Add source directories
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE
    src
)

# Add header files
target_sources(${CMAKE_PROJECT_NAME} PUBLIC
    src/template.hpp

    src/general/sort/insert.hpp
    src/general/sort/merge.hpp
    src/general/sort/merge_test.cpp

    src/general/array/max_subarray_test.cpp
    src/general/array/max_subarray.hpp
)

# Add implemetation files
target_sources(${CMAKE_PROJECT_NAME} PRIVATE
    src/main.cpp

    src/template.cpp

    src/general/sort/insert.cpp
    src/general/sort/merge.cpp

    src/general/array/max_subarray.cpp
)

# Add project symbols (macros)
target_compile_definitions(${CMAKE_PROJECT_NAME} PRIVATE
    # Add user defined symbols
)

# Link libraries
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE
    ${SOURCE_LIBRARY_NAME}
    GTest::GTest
)