# ============================================================================ #
# Source Files
# ============================================================================ #
set(ALL_FILES ${ALL_CPP})

add_library(
        Rooted
        STATIC
        include/rooted/block.h
        include/rooted/draw_pipe.h
        include/rooted/factory.h
        include/rooted/scope.h
        src/block/block.cpp
        src/block/nest.cpp
        src/block/print.cpp
        src/factory/factory.cpp
)
target_include_directories(Rooted
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

target_compile_features(Rooted PUBLIC cxx_std_20)