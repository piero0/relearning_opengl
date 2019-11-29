cmake_minimum_required(VERSION 3.14)

enable_language(CXX)

project(opengl04)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../)
add_executable(opengl04)

cmake_policy(SET CMP0076 NEW)
target_sources(opengl04 PUBLIC opengl04.cpp renderer.cpp)

target_include_directories(opengl04 PUBLIC ../pgfm/ ../libs)
target_compile_features(opengl04 PUBLIC cxx_std_17)

find_package(spdlog REQUIRED PATHS /usr/local/lib)

target_link_directories(opengl04 PUBLIC ../pgfm/build)
target_link_libraries(opengl04 pgfm GL GLEW spdlog::spdlog)

