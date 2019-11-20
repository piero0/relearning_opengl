#include "renderer.hpp"
#include <iostream>

void SimpleRenderer::setupShaders() {
    GLuint VertShader = glCreateShader(GL_VERTEX_SHADER);
    GLuint FragShader = glCreateShader(GL_FRAGMENT_SHADER);

    auto src = this->loadShader("vertexTriangle.glsl");
    const char* vertex_shader = src.c_str();
    
    glShaderSource(VertShader, 1, &vertex_shader, NULL);

    src = this->loadShader("fragment.glsl");
    const char* fragment_shader = src.c_str();

    glShaderSource(FragShader, 1, &fragment_shader, NULL);

    glCompileShader(VertShader);
    glCompileShader(FragShader);

    this->shaderProgram = glCreateProgram();
    glAttachShader(this->shaderProgram, VertShader);
    glAttachShader(this->shaderProgram, FragShader);

    glLinkProgram(this->shaderProgram);

    this->rgbLoc = glGetUniformLocation(this->shaderProgram, "rgb");
    glProgramUniform3f(this->shaderProgram, this->rgbLoc, this->r, this->g, this->b);
}

void SimpleRenderer::setupShadersPipeline() {
    auto src = this->loadShader("vertexTriangle.glsl");
    const char* vertex_shader = src.c_str();
    GLuint vertProg = glCreateShaderProgramv(GL_VERTEX_SHADER, 1, &vertex_shader);

    src = this->loadShader("fragment.glsl");
    const char* fragment_shader = src.c_str();
    GLuint fragProg = glCreateShaderProgramv(GL_FRAGMENT_SHADER, 1, &fragment_shader);    

    glGenProgramPipelines(1, &this->pip[0]);
    glBindProgramPipeline(this->pip[0]);

    glUseProgramStages(this->pip[0], GL_VERTEX_SHADER_BIT, vertProg);
    glUseProgramStages(this->pip[0], GL_FRAGMENT_SHADER_BIT, fragProg);

    this->rgbLoc = glGetUniformLocation(fragProg, "rgb");

    glActiveShaderProgram(this->pip[0], fragProg);
    glUniform3f(this->rgbLoc, this->r, this->g, this->b);
}

void SimpleRenderer::setupArrays() {
    glGenBuffers(1, &this->vbo[0]);
    glBindBuffer(GL_ARRAY_BUFFER, this->vbo[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(this->verts), this->verts, GL_STATIC_DRAW);

    glGenVertexArrays(1, &this->vao[0]);
    glBindVertexArray(this->vao[0]);

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(0);
}

void SimpleRenderer::setup() {
    this->setupShadersPipeline();
    std::cout << glGetError() << std::endl;
    this->setupArrays();
    std::cout << glGetError() << std::endl;

    glEnable(GL_PROGRAM_POINT_SIZE);
    glEnable(GL_CULL_FACE);
}

void SimpleRenderer::render() {
    //glUseProgram(this->shaderProgram);
    glDrawArrays(GL_TRIANGLES, 0, 6);
    
}
