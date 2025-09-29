cmake_minimum_required(VERSION 3.15)
project(FluidEngineProject)

# Utiliser C++17 ou plus
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include extern/glad/include extern/glm)

find_package(glfw3 3.3 REQUIRED)

# Fichiers sources
file(GLOB_RECURSE SOURCES
    src/*.cpp
    extern/glad/src/glad.c
)

# Créer l'exécutable
add_executable(${PROJECT_NAME} ${SOURCES})

# Lier les librairies nécessaires
target_link_libraries(${PROJECT_NAME} glfw GL)
