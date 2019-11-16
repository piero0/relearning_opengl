#include "renderer.hpp"

using namespace pgfm;
using namespace std::string_literals;

std::string Renderer::loadShader(std::string path) {
    std::ifstream file(path);

    auto line = ""s;
    auto source = ""s;

    while(std::getline(file, line)) {
        source += line + '\n';
    }

    file.close();

    return source;
}

void SimpleRenderer::setup() {
    GLuint VertShader = glCreateShader(GL_VERTEX_SHADER);
    GLuint FragShader = glCreateShader(GL_FRAGMENT_SHADER);

    auto src = this->loadShader("vertex.glsl");
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

    GLuint vao[1];
    glGenVertexArrays(1, vao);
    glBindVertexArray(vao[0]);
}

void SimpleRenderer::render() {
    glUseProgram(this->shaderProgram);
    glPointSize(15.0);
    glDrawArrays(GL_POINTS, 0, 1);
}
