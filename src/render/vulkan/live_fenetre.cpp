#include "live_fenetre.hpp"


namespace lve{

        livefenetre::livefenetre(int l, int h,std::string name){
            initi();

        };

        livefenetre::~livefenetre(){
            glfwDestroyWindow(fenetre);
            glfwTerminate();
          
        };


        void livefenetre::initi(){
            initi();
            glfwWindowHint(GLFW_CLIENT_API,GLFW_NO_API);
            glfwWindowHint(GLFW_RESIZABLE,GLFW_FALSE);
            fenetre = glfwCreateWindow(l,h,nom.c_str(),nullptr,nullptr)
        };
            
            
            
        fenetre = glfwCreateWindow(l,h,nom.c_str(),nullptr,nullptr);

      


        

       


};