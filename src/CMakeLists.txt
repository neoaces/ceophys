cmake_minimum_required(VERSION 3.10)

add_executable(neophys 
    main.c
)

target_link_libraries(neophys neolib neolog)

target_include_directories(neophys PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}"
)
