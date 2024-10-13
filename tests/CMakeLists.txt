set(CHECK_INSTALL_DIR "/opt/homebrew/Cellar/check/0.15.2")
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../src)

# If pkg-config is not installed on the system, then the
# CHECK_INSTALL_DIR variable must be set to the install
# location of Check. For example, on Windows, this may
# be: C:/Program Files/check
# set(CHECK_INSTALL_DIR "C:/Program Files/check")

find_package(Check REQUIRED)
include_directories(${CHECK_INCLUDE_DIRS})
link_directories(${CHECK_LIBRARY_DIRS})

cmake_minimum_required(VERSION 3.10)
set(TEST_SOURCES
    hash_t.c
)

add_executable(neotest ${TEST_SOURCES})
target_link_libraries(neotest neolib neolog ${CHECK_LIBRARIES})
