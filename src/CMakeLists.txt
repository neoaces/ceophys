cmake_minimum_required(VERSION 3.10)

add_executable(neophys 
    main.c
    window.h
    window.c
    "${PROJECT_SOURCE_DIR}/lib/glad/src/gl.c"
)

if (APPLE)
  target_link_libraries(neophys "-framework OpenGL")
endif()

find_package(OpenGL REQUIRED)
target_link_libraries(neophys neolib neolog glfw OpenGL::GL)

target_include_directories(neophys PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}"
                          "${PROJECT_SOURCE_DIR}/lib"
                          "${PROJECT_SOURCE_DIR}/lib/glad/include"
			  "${PROJECT_SOURCE_DIR}/lib/GLFW/include"
)
