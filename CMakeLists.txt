cmake_minimum_required(VERSION 3.27)

project(collatz)

file(GLOB sources src/*.cpp)
add_executable(collatz ${sources})

target_include_directories(collatz PRIVATE inc)

add_compile_options(-march=x86-64-v3)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_23)
