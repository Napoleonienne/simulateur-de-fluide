#include <glad/glad.h>
#include <vector>
static unsigned int compteur = 0;
std::vector<float> k;
 
class triangle{
    static GLuint VBO;
    static GLuint VAO;
    static unsigned int compteur = compteur+ 1;
    static std::vector<float> k;
    public: 
        triangle(const float x,const float y,const float z,const float largeur,const float hauteur){
            
       std::vector<float> forme ={
                (x+(largeur/2)),  (y), z,
                (x+(largeur/2)), (y), z,
                (x), (y+hauteur), z
                };

        k.insert(k.end(),forme.begin(),forme.end());
            
            
};

//probleme les triangle on tous le meme shader gl enable vertex est un peu merdique  
        void draw(){
            glGenVertexArrays(compteur, &VAO);
            glGenBuffers(compteur, &VBO);

            glBindVertexArray(VAO);

            glBindBuffer(GL_ARRAY_BUFFER, VBO);
            glBufferData(GL_ARRAY_BUFFER,( k.size()*sizeof(float) ), k.data() , GL_STATIC_DRAW);
            glEnableVertexAttribArray(0);

        }







        };
        
