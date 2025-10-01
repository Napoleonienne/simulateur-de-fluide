#include <glad/glad.h>

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

class triangle{
    static GLuint vbo
    static GLuint vao
    compte =
    public:
        triangle(float x,float y,float z,float largeur,)





}