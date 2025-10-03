cmake_minimum_required(VERSION 3.15)
project(FluidEngineProject)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# --- Vulkan ---
find_package(Vulkan REQUIRED)

# --- Includes ---
include_directories(
    include
    ${CMAKE_SOURCE_DIR}/include
    externe/glm
    externe/imgui/include
    externe/fmodstudioapi20309linux/api/core/inc
)

# --- Sources ---
file(GLOB_RECURSE SOURCES
    src/*.cpp
    externe/imgui/src
    externe/fmodstudioapi20309linux/api/core/lib
    include/
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
        Vulkan::Vulkan 
    )
else()
    message(FATAL_ERROR "GLFW not found. Install it and try again.")
endif()

# --- glslc ---
find_program(GLSLC glslc)

if(NOT GLSLC)
    message(FATAL_ERROR "glslc (Vulkan Shader Compiler) non trouvé. Installez-le via le SDK Vulkan.")
endif()



# --- Shaders ---
set(SHADER_DIR "${CMAKE_CURRENT_SOURCE_DIR}/shaders")
set(SHADER_OUTPUT_DIR "${CMAKE_CURRENT_BINARY_DIR}/shaders_compiled")
file(MAKE_DIRECTORY ${SHADER_OUTPUT_DIR})

file(GLOB SHADERS CONFIGURE_DEPENDS
    ${SHADER_DIR}/*.vert
    ${SHADER_DIR}/*.frag
    ${SHADER_DIR}/*.comp   # ajout compute shaders
)

set(SPIRV_SHADERS "")
foreach(SHADER ${SHADERS})
    get_filename_component(SHADER_NAME ${SHADER} NAME)
    set(SPIRV_OUTPUT "${SHADER_OUTPUT_DIR}/${SHADER_NAME}.spv")

    add_custom_command(
        OUTPUT ${SPIRV_OUTPUT}
        COMMAND ${CMAKE_COMMAND} -E echo "[GLSLC] Compilation : ${SHADER_NAME}"
        COMMAND ${GLSLC} -V ${SHADER} -o ${SPIRV_OUTPUT}
        DEPENDS ${SHADER}
    )

    list(APPEND SPIRV_SHADERS ${SPIRV_OUTPUT})
endforeach()

add_custom_target(Shaders DEPENDS ${SPIRV_SHADERS})
add_dependencies(simulateur_de_fluide Shaders)