cmake_minimum_required(VERSION 3.22)
project(UwbService VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Own ----------------------------------------------------------------------------------#
add_executable(${CMAKE_PROJECT_NAME})

target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC
    src
)

target_sources(${CMAKE_PROJECT_NAME} PUBLIC
    src/template.hpp
)

# Add sources to executable
target_sources(${CMAKE_PROJECT_NAME} PRIVATE
    src/main.cpp
    src/template.cpp
)

# Add project symbols (macros)
target_compile_definitions(${CMAKE_PROJECT_NAME} PRIVATE
    # Add user defined symbols
)

# Связываем цель сборки с динамическими библиотеками
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE
)
