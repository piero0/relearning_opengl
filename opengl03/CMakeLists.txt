cmake_minimum_required(VERSION 3.14)

enable_language(CXX)

project(opengl03)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../)
add_executable(opengl03)

cmake_policy(SET CMP0076 NEW)
target_sources(opengl03 PUBLIC opengl03.cpp renderer.cpp appwindow.cpp util.cpp)

target_compile_features(opengl03 PUBLIC cxx_std_17)

target_link_libraries(opengl03 stdc++fs glfw GL GLEW pthread)
