cmake_minimum_required(VERSION 3.10)
add_library(neolib STATIC neolib.c)
target_link_libraries(neolib raylib)
target_include_directories(neolib PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}"
                          "${PROJECT_SOURCE_DIR}/lib/raylib"
                          "${PROJECT_SOURCE_DIR}/lib/raygui/src"
)
