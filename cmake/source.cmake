# ============================================================================ #
# Source Files
# ============================================================================ #
file(GLOB_RECURSE ALL_CPP "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
file(GLOB_RECURSE ALL_H   "${CMAKE_CURRENT_SOURCE_DIR}/*.h")
set(ALL_FILES ${ALL_CPP} ${ALL_H})

# Exclude generated build files
foreach(file ${ALL_FILES})
    if(file MATCHES "${CMAKE_BINARY_DIR}")
        list(REMOVE_ITEM ALL_FILES ${file})
    endif()
endforeach()

add_library(Rooted STATIC ${ALL_FILES})
target_include_directories(Rooted
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

target_compile_features(Rooted PUBLIC cxx_std_20)