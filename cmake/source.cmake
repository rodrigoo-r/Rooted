# ============================================================================ #
# Source Files
# ============================================================================ #
file(GLOB_RECURSE ROOTED_INTERNAL_ALL_CPP "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
file(GLOB_RECURSE ROOTED_INTERNAL_ALL_H   "${CMAKE_CURRENT_SOURCE_DIR}/include/*.h")
set(ROOTED_INTERNAL_ALL_FILES ${ROOTED_INTERNAL_ALL_CPP} ${ROOTED_INTERNAL_ALL_H})

add_library(Rooted STATIC ${ROOTED_INTERNAL_ALL_FILES})
add_library(Rooted::Rooted ALIAS Rooted)
target_include_directories(Rooted
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

target_compile_features(Rooted PUBLIC cxx_std_20)