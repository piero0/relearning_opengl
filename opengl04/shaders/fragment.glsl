#version 460

in vec2 tc;
layout ( binding = 0 ) uniform sampler2D sampl;
layout ( location = 0 ) out vec4 color;

void main() { 
    color = texture(sampl, tc);
}