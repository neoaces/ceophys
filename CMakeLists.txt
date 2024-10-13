cmake_minimum_required(VERSION 3.10)
project(neophys CXX C)

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

enable_testing() # enables testing

add_subdirectory(lib/googletest) # add googletest subdirectory
include(GoogleTest)

add_subdirectory(neolog)
add_subdirectory(neolib)
add_subdirectory(tests)
add_subdirectory(src)
