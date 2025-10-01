#include <glad/glad.h>
#include <vector>
std::vector<float> k;
GLuint VBO;
GLuint VAO;
unsigned int compteur;
class triangle{
   
    static unsigned int compteur;
   
    static std::vector<float> totale_vertice;
    public: 
        triangle(const float x,const float y,const float z,const float largeur,const float hauteur){
            compteur ++;
        
       std::vector<float> forme ={
                (x+(largeur/2)),  (y), z,
                (x-(largeur/2)), (y), z,
                (x), (y+hauteur), z
                };
        totale_vertice.insert(totale_vertice.end(),forme.begin(),forme.end());
            
        
};
        void bind(){
            glGenVertexArrays(1, &VAO);
            glGenBuffers(1, &VBO);

            glBindVertexArray(VAO);
        }
        void lier(){

            glBindBuffer(GL_ARRAY_BUFFER, VBO);
            glBufferData(GL_ARRAY_BUFFER,( totale_vertice.size()*sizeof(float) ), totale_vertice.data() , GL_STATIC_DRAW);


            glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE,  totale_vertice.size()* sizeof(float), (void*)(3 * sizeof(float)));
            glEnableVertexAttribArray(0);
            glDrawArrays(GL_TRIANGLES, 0, 3);
 
        }
        void draw(){
            glDrawArrays(GL_TRIANGLES, 0, 3);


        }






        static void suprimer(){
            glDeleteBuffers(1,&VBO);
            glDeleteVertexArrays(1, &VAO);
        }







        };
        
