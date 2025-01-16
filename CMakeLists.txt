cmake_minimum_required(VERSION 3.10)
project(AcharNumeros)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
add_executable(AcharNumeros ../AcharSoma.cpp ../ReadFile.cpp)
add_custom_command(TARGET AcharNumeros
                   POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:AcharNumeros> ..)

