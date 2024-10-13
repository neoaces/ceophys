cmake_minimum_required(VERSION 3.10)
set(TEST_SOURCES
    hash_t.cpp
)

add_executable(neotest ${TEST_SOURCES})
target_link_libraries(neotest neolib neolog gtest)

target_include_directories(neotest PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/neolog"
                          "${PROJECT_SOURCE_DIR}/neolib"
                          "${PROJECT_SOURCE_DIR}/lib/googletest/googletest/include"
)
