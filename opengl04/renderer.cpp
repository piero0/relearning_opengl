#include "renderer.hpp"
#include "util.hpp"
#include <spdlog/spdlog.h>
#include <iostream>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

SimpleRenderer::~SimpleRenderer() {
    stbi_image_free(this->tex_data);
}

void SimpleRenderer::setupShadersPipeline() {
    auto src = pgfm::Util::loadShader("shaders/vertexTriangle.glsl");
    const char* vertex_shader = src.c_str();
    GLuint vertProg = glCreateShaderProgramv(GL_VERTEX_SHADER, 1, &vertex_shader);
    int len = 0;
    char infoLog[2048] = {0};
    glGetProgramInfoLog(vertProg, 2048, &len, infoLog);
    spdlog::warn("VertShader log: {0}", infoLog);

    src = pgfm::Util::loadShader("shaders/fragment.glsl");
    const char* fragment_shader = src.c_str();
    GLuint fragProg = glCreateShaderProgramv(GL_FRAGMENT_SHADER, 1, &fragment_shader);    
    glGetProgramInfoLog(vertProg, 2048, &len, infoLog);
    spdlog::warn("FragShader log: {0}", infoLog);

    glGenProgramPipelines(1, &this->pip[0]);
    glBindProgramPipeline(this->pip[0]);

    glUseProgramStages(this->pip[0], GL_FRAGMENT_SHADER_BIT, fragProg);
    glUseProgramStages(this->pip[0], GL_VERTEX_SHADER_BIT, vertProg);

    glActiveShaderProgram(this->pip[0], fragProg);

    spdlog::info("Shaders pipeline set up");
}

void SimpleRenderer::setupArrays() {
    glGenBuffers(3, &this->vbo[0]);

    glBindBuffer(GL_ARRAY_BUFFER, this->vbo[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(this->verts), this->verts, GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, this->vbo[2]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(this->uv), this->uv, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->vbo[1]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(this->indexes), this->indexes, GL_STATIC_DRAW);

    glGenVertexArrays(1, &this->vao[0]);
    glBindVertexArray(this->vao[0]);

    glVertexArrayElementBuffer(this->vao[0], this->vbo[1]);

    glBindBuffer(GL_ARRAY_BUFFER, this->vbo[0]);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, this->vbo[2]);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(1);

    spdlog::info("VAO and VBO set up");
}

void SimpleRenderer::setupTexture() {
    int width, height, channels;
    stbi_set_flip_vertically_on_load(true);
    this->tex_data = stbi_load("imgs/brick.jpg", &width, &height, &channels, 0);

    spdlog::info("Texture size: {0}x{1}", width, height);

    glGenTextures(1, &this->tex[0]);

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, this->tex[0]);

    glPixelStorei(GL_UNPACK_ALIGNMENT, 1); //why and how?

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, this->tex_data);
    glGenerateMipmap(GL_TEXTURE_2D);

    spdlog::info("Textures set up");
}

void SimpleRenderer::setup() {
    this->setupArrays();
    this->setupShadersPipeline();
    this->setupTexture();
    
    glEnable(GL_PROGRAM_POINT_SIZE);
    glEnable(GL_CULL_FACE);

    spdlog::info("Setup done");
}

void SimpleRenderer::render() {    
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}
