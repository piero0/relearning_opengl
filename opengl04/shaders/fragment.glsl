#version 460

layout ( location = 0 ) out vec4 color;
uniform vec3 rgb;

void main() { 
    if(gl_PrimitiveID < 1)
        color = vec4(rgb, 1.0);
    else
        color = vec4(0.0, 1.0, 0.0, 1.0);
}