cmake_minimum_required(VERSION 3.14)

enable_language(CXX)

project(pgfm)

add_library(pgfm)
option(BUILD_SHARED_LIBS "so" ON)

cmake_policy(SET CMP0076 NEW)
target_sources(pgfm PUBLIC appwindow.cpp util.cpp)
target_include_directories(pgfm PUBLIC ../libs)

find_package(spdlog REQUIRED PATHS /usr/local/lib)

target_compile_features(pgfm PUBLIC cxx_std_17)

target_link_libraries(pgfm PUBLIC spdlog::spdlog_header_only stdc++fs glfw GL GLEW pthread)
