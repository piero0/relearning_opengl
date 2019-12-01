#pragma once
#include "util.hpp"
#include "baserenderer.hpp"

class SimpleRenderer: public pgfm::BaseRenderer {
    private:
        GLuint shaderProgram;

        GLuint vao[1] = {0};
        GLuint vbo[3] = {0};
        GLuint pip[1] = {0};
        GLuint tex[1] = {0};

        pgfm::Image texObj;

        GLfloat verts[8] = {                
            -0.75f, -0.75f,
            0.75f, -0.75f,
            -0.75f, 0.75f,
            0.75f, 0.75f,
        };

        GLfloat uv[8] {
            0.0f, 0.0f,
            1.0f, 0.0f,
            0.0f, 1.0f,
            1.0f, 1.0f,
        };

        GLuint indexes[6] {
            0, 1, 2,
            2, 1, 3,
        };

        float r = 0.7f, g = 0.f, b = 0.f;
        GLuint rgbLoc = 0;

    public:
        SimpleRenderer() = default;
        ~SimpleRenderer() = default;

        void setupShaders();
        void setupShadersPipeline();
        void setupArrays();
        void setupTexture();

        void setup() override;
        void render() override;
};
