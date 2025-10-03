#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <glm.hpp>
#include <matrix.hpp>
#include <glm.hpp>
#include "shader.cpp"
#include "triangle.h"
#include <vulkan/vulkan.h>

const uint16_t h = 800, l = 600;
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);
void error_callback(int error, const char* description);

int main()
{   //initialisation

    





} 
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // Met à jour la zone d'affichage OpenGL
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

}


void error_callback(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
}

