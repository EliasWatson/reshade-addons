cmake_minimum_required(VERSION 3.13)

project(TextureTools)
set(CMAKE_CXX_STANDARD 17)

add_compile_definitions(
    NDEBUG
    IMGUI_DISABLE_DEMO_WINDOWS
    IMGUI_DISABLE_METRICS_WINDOW
    IMGUI_DEFINE_MATH_OPERATORS
    IMGUI_DISABLE_OBSOLETE_FUNCTIONS
)

set(IMGUI_SRC
    ${CMAKE_CURRENT_SOURCE_DIR}/deps/imgui/imgui.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/deps/imgui/imgui_draw.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/deps/imgui/imgui_tables.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/deps/imgui/imgui_widgets.cpp
)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/deps/reshade/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/deps/imgui)
add_library(TextureTools SHARED texture_tools/texture_tools.cpp ${IMGUI_SRC})

install(TARGETS TextureTools DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)
