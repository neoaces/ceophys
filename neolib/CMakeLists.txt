cmake_minimum_required(VERSION 3.10)
add_library(neolib STATIC neolib.c engine.c window.c force.c solver.c)

target_link_libraries(neolib neolog raylib)

target_include_directories(neolib PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}"
                          "${PROJECT_SOURCE_DIR}/lib/raylib"
                          "${PROJECT_SOURCE_DIR}/lib/raygui/src"
                          "${PROJECT_SOURCE_DIR}/lib/neolog/"
)
