#version 460

layout (location = 0) in vec2 verts;

out gl_PerVertex {
    vec4 gl_Position;
    float gl_PointSize;
};

void main() { 
    gl_Position = vec4(verts, 0.0, 1.0);
    gl_PointSize = 1.0;
}