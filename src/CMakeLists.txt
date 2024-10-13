cmake_minimum_required(VERSION 3.10)

set(BAKENDS_FOLDER "${CMAKE_SOURCE_DIR}/lib/cimgui/imgui/backends/")
set(TABLES_SOURCE "${CMAKE_SOURCE_DIR}/lib/cimgui/imgui/imgui_tables.cpp")

set(IMGUI_SOURCES 
    "${CMAKE_SOURCE_DIR}/lib/cimgui/cimgui.cpp"
    "${CMAKE_SOURCE_DIR}/lib/cimgui/imgui/imgui.cpp"
    "${CMAKE_SOURCE_DIR}/lib/cimgui/imgui/imgui_draw.cpp"
    "${CMAKE_SOURCE_DIR}/lib/cimgui/imgui/imgui_demo.cpp"
    "${CMAKE_SOURCE_DIR}/lib/cimgui/imgui/imgui_widgets.cpp"
    ${TABLES_SOURCE}
)

# FREETYPE
option(IMGUI_FREETYPE "add Freetype2" ON)

if(IMGUI_FREETYPE)
	FIND_PACKAGE(freetype REQUIRED PATHS ${FREETYPE_PATH})
	list(APPEND IMGUI_LIBRARIES freetype)
	list(APPEND IMGUI_SOURCES ${CMAKE_SOURCE_DIR}/lib/cimgui/imgui/misc/freetype/imgui_freetype.cpp)
	add_definitions("-DCIMGUI_FREETYPE=1")
endif(IMGUI_FREETYPE)

# OPENGL
list(APPEND IMGUI_SOURCES ${BAKENDS_FOLDER}/imgui_impl_opengl3.cpp)
list(APPEND IMGUI_SOURCES ${BAKENDS_FOLDER}/imgui_impl_glfw.cpp)

add_library(cimgui STATIC ${IMGUI_SOURCES})
target_compile_definitions(cimgui PUBLIC "-DIMGUI_IMPL_API=extern \"C\" ")
target_link_libraries(cimgui glfw "-framework OpenGL")
add_executable(neophys 
    main.c
    window.h
    window.c
    ${CMAKE_SOURCE_DIR}/lib/glad/src/gl.c
    ${CMAKE_SOURCE_DIR}/lib/cimgui/cimgui.cpp
)

target_link_libraries(neophys neolib neolog cimgui glfw)

target_include_directories(neophys PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}"
                          "${PROJECT_SOURCE_DIR}/lib"
                          "${PROJECT_SOURCE_DIR}/lib/cimgui/generator/output"
                          "${PROJECT_SOURCE_DIR}/lib/glad/include"
)
