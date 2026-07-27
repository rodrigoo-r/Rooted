cmake_minimum_required(VERSION 4.1)
project(Rooted)

add_library(Rooted INTERFACE)
add_library(Rooted::Rooted ALIAS Rooted)

target_include_directories(Rooted
        INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

target_compile_features(Rooted
        INTERFACE cxx_std_20
)