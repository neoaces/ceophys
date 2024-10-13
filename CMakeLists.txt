cmake_minimum_required(VERSION 3.10)
project(neophys CXX C)
enable_testing()
# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_C_STANDARD 99)

if(CMAKE_COMPILER_IS_GNUCXX)
    message("Using GCC")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fprofile-arcs -ftest-coverage")
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    message("Using Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} --coverage")
else()
    message(WARNING "Code coverage requires GCC or Clang. Compiler is ${CMAKE_CXX_COMPILER_ID}")
endif()

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(CTest)
add_subdirectory(lib/googletest) # add googletest subdirectory
add_subdirectory(lib/glfw)

add_subdirectory(neolog)
add_subdirectory(neolib)
add_subdirectory(tests)
add_subdirectory(src)
