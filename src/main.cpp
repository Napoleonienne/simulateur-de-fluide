#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>


const uint16_t h = 800, l = 600;

int main()
{
    if (!glfwInit()){
        std::cout << "opengl ne c'est pas chargé";
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4); 
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6); 
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); 

    GLFWwindow* fenetre = glfwCreateWindow(l,h,"engine v1",NULL,NULL);
    

    







    return 0;
}