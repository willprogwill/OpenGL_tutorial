#version 330 core

// Input vertex data, different for all executions of this shader.
layout(location = 0) in vec3 vertexPosition_modelspace;

void main(){

    gl_Position.xyz = vertexPosition_modelspace;
    gl_Position.w = 1.0;
    //gl_Position.x = gl_Position.x - 1.0;
    //gl_Position.y = gl_Position.y - 1.0;

}
