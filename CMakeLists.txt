cmake_minimum_required(VERSION 3.16)



project(MyProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ------------------------------------------------------------
# Buscar todos los .cc y .h de src
# ------------------------------------------------------------
file(GLOB_RECURSE SRC_FILES
    src/*.cc
    src/*.cpp
    src/*.c
    src/*.h
    src/*.hpp
)

# ------------------------------------------------------------
# ImGui
# ------------------------------------------------------------
set(IMGUI_DIR ${CMAKE_SOURCE_DIR}/external/imgui-master)

set(IMGUI_SRC
    ${IMGUI_DIR}/imgui.cpp
    ${IMGUI_DIR}/imgui_demo.cpp
    ${IMGUI_DIR}/imgui_draw.cpp
    ${IMGUI_DIR}/imgui_tables.cpp
    ${IMGUI_DIR}/imgui_widgets.cpp
)

# ------------------------------------------------------------
# rlImGui
# ------------------------------------------------------------
set(RLIMGUI_DIR ${CMAKE_SOURCE_DIR}/external/rlImGui-main)

set(RLIMGUI_SRC
    ${RLIMGUI_DIR}/rlImGui.cpp
)

# ------------------------------------------------------------
# Ejecutable
# ------------------------------------------------------------
add_executable(${PROJECT_NAME}
    ${SRC_FILES}
    ${IMGUI_SRC}
    ${RLIMGUI_SRC}
)

# ------------------------------------------------------------
# Includes
# ------------------------------------------------------------
target_include_directories(${PROJECT_NAME} PRIVATE
    src
    ${IMGUI_DIR}
    ${RLIMGUI_DIR}
    ${CMAKE_SOURCE_DIR}/external/raylib-6.0_win64_mingw-w64/include
)

# ------------------------------------------------------------
# Raylib
# ------------------------------------------------------------
target_link_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_SOURCE_DIR}/external/raylib-6.0_win64_mingw-w64/lib
)

target_link_libraries(${PROJECT_NAME}
    raylib
    opengl32
    gdi32
    winmm
)

# ------------------------------------------------------------
# Windows
# ------------------------------------------------------------
if(WIN32)
    target_compile_definitions(${PROJECT_NAME} PRIVATE PLATFORM_DESKTOP)
endif()