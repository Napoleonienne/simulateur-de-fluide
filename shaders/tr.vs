#version 460 core
layout (location = 0) in vec3 pos;
out vec4 gl_Position

void main()
{
    gl_Position = vec4(pos.x,pos.y,pos.z, 1.0); 
 
 
}

k