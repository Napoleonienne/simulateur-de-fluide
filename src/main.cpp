#include <GLFW/glfw3.h>
#include <iostream>
#include <glm.hpp>
#include <matrix.hpp>
#include <vulkan/vulkan.h>
#include "app.hpp"
#include <stdlib.h>
#include <printf.h>
#include <stdexcept>


const uint16_t h = 800, l = 600;
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);
void error_callback(int error, const char* description);

int main()
{   //initialisation
    lve::app app;

        try{
                app.run();
        }
        catch(const std::exception &e){
                std::cerr << e.what() << "\n";
                return EXIT_FAILURE;

        }




        return EXIT_SUCCESS;

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

