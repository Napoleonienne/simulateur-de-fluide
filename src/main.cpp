#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

const uint16_t h = 800, l = 600;
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);
void error_callback(int error, const char* description);

int main()
{   //initialisation
    glfwSetErrorCallback(error_callback);
    if (!glfwInit()){
        std::cout << "opengl ne c'est pas chargé";
    }


    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4); 
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6); 
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); 


    GLFWwindow* window = glfwCreateWindow(l,h,"engine v1",NULL,NULL);
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    #ifdef __APPLE__
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // Compatibilité MacOS
    #endif

    

    





    while (!glfwWindowShouldClose(window))
    {
        processInput(window);//p





        glfwSwapBuffers(window);//d
    }

    glfwTerminate();
    return 0;
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
