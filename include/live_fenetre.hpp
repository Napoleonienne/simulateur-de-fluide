#pragma onnce 
#define GLFW_INCUDE_VULKAN //vulkan header
#include<GLFW/glfw3.h>
#include <string>




namespace lve{
class livefenetre{

    public:
        livefenetre(int l, int h,std::string name);

        ~livefenetre();


    private:
        void initi();
        const int l;
        const int h;

        std::string nom;
        GLFWwindow *fenetre;

    };

};