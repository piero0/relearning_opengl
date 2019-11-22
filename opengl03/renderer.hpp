#pragma once
#include "baserenderer.hpp"

class SimpleRenderer: public pgfm::BaseRenderer {
    private:
        GLuint shaderProgram;

        GLuint vao[1] = {0};
        GLuint vbo[2] = {0};
        GLuint pip[1] = {0};

        GLfloat verts[8] = {                
            -1.0f, 1.0f,
            -1.0f, -1.0f,
            1.0f, -1.0f,
            1.0f, 1.0f,
        };

        GLuint indexes[6] {
            0, 1, 2,
            2, 3, 0,
        };

        float r = 0.7f, g = 0.f, b = 0.f;
        GLuint rgbLoc = 0;

    public:
        SimpleRenderer() = default;
        ~SimpleRenderer() = default;

        void setupShaders();
        void setupShadersPipeline();
        void setupArrays();

        void setup() override;
        void render() override;
};
