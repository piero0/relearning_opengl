cmake_minimum_required(VERSION 3.12)

enable_language(CXX)

project(opengl02)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../)
add_executable(opengl02)

cmake_policy(SET CMP0076 NEW)
target_sources(opengl02 PUBLIC opengl02.cpp baserenderer.cpp renderer.cpp appwindow.cpp)

target_compile_features(opengl02 PUBLIC cxx_std_17)

target_link_libraries(opengl02 stdc++fs glfw GL GLEW pthread)
