#version 460

layout (location = 0) in vec2 verts;

void main() { 
    gl_Position = vec4(verts, 0.0, 1.0);
    gl_PointSize = 1.0;
}