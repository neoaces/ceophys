cmake_minimum_required(VERSION 3.10)
add_library(neolib STATIC engine.c models.c solver.c)

target_link_libraries(neolib neolog)
target_include_directories(neolib PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}"
)
