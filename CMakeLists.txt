cmake_minimum_required(VERSION 3.15)
project(FluidEngineProject)

# Utiliser C++17 ou plus
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(
    include 
    externe/glad/
    externe/glm
)

find_package(glfw3 3.3 REQUIRED)

# Fichiers sources
file(GLOB_RECURSE SOURCES
    src/*.cpp
    externe/glad/src/glad.c
)

# Créer l'exécutable (donne un nom sans espaces)
add_executable(simulateur_de_fluide ${SOURCES})

# Lier les librairies nécessaires
target_link_libraries(simulateur_de_fluide glfw GL)
