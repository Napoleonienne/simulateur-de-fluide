#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <glm.hpp>
#include <matrix.hpp>
#include <ext/matrix_clip_space.hpp>
#include <glm.hpp>
#include "shader.cpp"
#include "triangle.h"



void createScene(int l,int h, float fov ){
        
        glm::mat4 perspertives = glm::perspective(glm::radians(fov), (float)l/(float)h, 0.1f, 100.0f);
        glm::vec3::c





}