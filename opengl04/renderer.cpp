#include "renderer.hpp"
#include "util.hpp"
#include <spdlog/spdlog.h>
#include <iostream>

void SimpleRenderer::setupShadersPipeline() {
    auto src = pgfm::Util::loadShader("shaders/vertexTriangle.glsl");
    const char* vertex_shader = src.c_str();
    GLuint vertProg = glCreateShaderProgramv(GL_VERTEX_SHADER, 1, &vertex_shader);
    int len = 0;
    char infoLog[2048] = {0};
    glGetProgramInfoLog(vertProg, 2048, &len, infoLog);

    src = pgfm::Util::loadShader("shaders/fragment.glsl");
    const char* fragment_shader = src.c_str();
    GLuint fragProg = glCreateShaderProgramv(GL_FRAGMENT_SHADER, 1, &fragment_shader);    

    glGenProgramPipelines(1, &this->pip[0]);
    glBindProgramPipeline(this->pip[0]);

    glUseProgramStages(this->pip[0], GL_FRAGMENT_SHADER_BIT, fragProg);

    glUseProgramStages(this->pip[0], GL_VERTEX_SHADER_BIT, vertProg);

    this->rgbLoc = glGetUniformLocation(fragProg, "rgb");

    glActiveShaderProgram(this->pip[0], fragProg);
    glUniform3f(this->rgbLoc, this->r, this->g, this->b);

    //glUseProgram(0);
    spdlog::info("Shaders pipeline set up");
}

void SimpleRenderer::setupArrays() {
    glGenBuffers(2, &this->vbo[0]);
    glBindBuffer(GL_ARRAY_BUFFER, this->vbo[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(this->verts), this->verts, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->vbo[1]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(this->indexes), this->indexes, GL_STATIC_DRAW);

    glGenVertexArrays(1, &this->vao[0]);
    glBindVertexArray(this->vao[0]);

    glVertexArrayElementBuffer(this->vao[0], this->vbo[1]);

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);
    
    glEnableVertexAttribArray(0);

    spdlog::info("VAO and VBO set up");
}

void SimpleRenderer::setup() {
    this->setupArrays();
    this->setupShadersPipeline();
    
    glEnable(GL_PROGRAM_POINT_SIZE);
    glEnable(GL_CULL_FACE);

    spdlog::info("Setup done");
}

void SimpleRenderer::render() {    
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    //glDrawArrays(GL_TRIANGLES, 0, 6);
}
