set(CMAKE_TRY_COMPILE_TARGET_TYPE "STATIC_LIBRARY")
set(CMAKE_C_COMPILER_WORKS True)
set(CMAKE_CXX_COMPILER_WORKS True)
cmake_minimum_required(VERSION 3.10)
project(Practice)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
add_subdirectory(lib/AcharSoma)
list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/lib/AcharSoma")
add_executable(Practice Main.cpp)
target_link_libraries(Practice PUBLIC AcharSoma)
add_custom_command(TARGET Practice
                   POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:Practice> ..)

