#include "renderer.hpp"
#include <string>
#include <iostream>

using namespace pgfm;

void SimpleRenderer::setup() {
    const char* vertex_shader = 
        "#version 460\n"
        "void main(void)\n"
        "{ gl_Position = vec4(0.0, 0.0, 0.0, 1.0); }";

    const char* fragment_shader =
        "#version 460\n"
        "out vec4 color;\n"
        "void main(void)\n"
        "{ color = vec4(0.0, 0.0, 1.0, 1.0); }";

    GLuint VertShader = glCreateShader(GL_VERTEX_SHADER);
    GLuint FragShader = glCreateShader(GL_FRAGMENT_SHADER);

    glShaderSource(VertShader, 1, &vertex_shader, NULL);
    glShaderSource(FragShader, 1, &fragment_shader, NULL);

    glCompileShader(VertShader);
    glCompileShader(FragShader);


    this->shaderProgram = glCreateProgram();
    glAttachShader(this->shaderProgram, VertShader);
    glAttachShader(this->shaderProgram, FragShader);

    glLinkProgram(this->shaderProgram);

    GLuint vao[1];
    glGenVertexArrays(1, vao);
    glBindVertexArray(vao[0]);

}

void SimpleRenderer::render() {
    glUseProgram(this->shaderProgram);
    glDrawArrays(GL_POINTS, 0, 1);
}
