#include <glad/glad.h>

 
class triangle{
    static GLuint VBO;
    static GLuint VAO;
    static unsigned int compteur;
    public:
        triangle(float x,float y,float z,float largeur,float hauteur){
            float p1=;
            float p2=;
            float p3=;



            float forme[9] ={
                0.3f,  0.7f, 0.0f,
                -0.8f, -0.2f, 0.0f,
                0.4f, -0.9f, 0.0f
                };
            }
        void tr(){
            glGenVertexArrays(compteur, &VAO);
            glGenBuffers(compteur, &VBO);

            glBindVertexArray(VAO);

            glBindBuffer(GL_ARRAY_BUFFER, VBO);
            glBufferData(GL_ARRAY_BUFFER, sizeof(triangle), triangle, GL_STATIC_DRAW);




        }







        }
        





}