#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <GL/glew.h>

namespace pgfm
{
    class Renderer {
        public:
            virtual void setup() = 0;
            virtual void render() = 0;
            std::string loadShader(std::string path);
    };

    class SimpleRenderer: public Renderer {
        private:
            GLuint shaderProgram;

        public:
            void setup() override;
            void render() override;
    };
} 
