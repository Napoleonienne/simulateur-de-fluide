#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <glm.hpp>
#include <matrix.hpp>
#include <ext/matrix_clip_space.hpp>
#include "shader.cpp"


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
    float fov= 45.0f;

    glm::mat4 proj = glm::perspective(glm::radians(fov), (float)l/(float)h, 0.1f, 100.0f);
    float triangle[9] ={
     0.3f,  0.7f, 0.0f,
    -0.8f, -0.2f, 0.0f,
     0.4f, -0.9f, 0.0f
    };
    GLuint VAO, VBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(triangle), triangle, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    Shader shader_triangle  = Shader("shader/vertex/tr.vs","shader/fragmen/tr.fs");




    





    while (!glfwWindowShouldClose(window))
    {
        processInput(window);//p
        glClearColor(0.749f, 0.0f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        shader_triangle.use();


        glDrawArrays(GL_TRIANGLES, 0, 3);
        glfwSwapBuffers(window);//d
    }
    glDeleteBuffers(1,&VBO);

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

