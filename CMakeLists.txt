cmake_minimum_required(VERSION 3.15)
project(FluidEngineProject)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# --- Includes ---
include_directories(
    include
    ${CMAKE_SOURCE_DIR}/include
    externe/glad/include
    externe/glm
)

# --- Sources ---
file(GLOB_RECURSE SOURCES
    src/*.cpp
    externe/glad/src/glad.c
)

# --- Executable ---
add_executable(simulateur_de_fluide ${SOURCES})

# --- GLFW via pkg-config ---
find_package(PkgConfig REQUIRED)
pkg_search_module(GLFW REQUIRED glfw3)

if(GLFW_FOUND)
    include_directories(${GLFW_INCLUDE_DIRS})
    link_directories(${GLFW_LIBRARY_DIRS})
    target_link_libraries(simulateur_de_fluide
        ${GLFW_LIBRARIES}   # glfw
        GL                  # OpenGL
        X11 Xrandr Xi Xxf86vm Xcursor pthread dl m  # dépendances Linux
    )
else()
    message(FATAL_ERROR "GLFW not found. Install it and try again.")
endif()
