#include <glad/glad.h>
#include <vector>
std::vector<float> k;
 
class triangle{
    static GLuint VBO;
    static GLuint VAO;
    static unsigned int compteur;
    compteur ++;
    static std::vector<float> totale_vertice;
    public: 
        triangle(const float x,const float y,const float z,const float largeur,const float hauteur){
        
       std::vector<float> forme ={
                (x+(largeur/2)),  (y), z,
                (x+(largeur/2)), (y), z,
                (x), (y+hauteur), z
                };
        totale_vertice.insert(k.end(),forme.begin(),forme.end());
            
        
};

        void draw(){
            glGenVertexArrays(compteur, &VAO);
            glGenBuffers(compteur, &VBO);

            glBindVertexArray(VAO);

            glBindBuffer(GL_ARRAY_BUFFER, VBO);
            glBufferData(GL_ARRAY_BUFFER,( k.size()*sizeof(float) ), k.data() , GL_STATIC_DRAW);
            glEnableVertexAttribArray(0);

        }







        };
        
