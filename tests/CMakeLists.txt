set(TEST_SOURCES
    hmap.cpp
)

add_executable(neotest ${TEST_SOURCES})
target_link_libraries(neotest PRIVATE GTest::gtest_main)

target_include_directories(neolib PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}"
)

include(GoogleTest)
gtest_discover_tests(neotest)
