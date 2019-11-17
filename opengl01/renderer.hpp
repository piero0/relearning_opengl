#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <filesystem>
#include <GL/glew.h>

namespace pgfm
{
    class BaseRenderer {
        protected:
            std::filesystem::path shadersPath = "shaders";

        public:
            virtual void setup() = 0;
            virtual void render() = 0;
            std::string loadShader(std::string name);
    };

    class SimpleRenderer: public BaseRenderer {
        private:
            GLuint shaderProgram;

        public:
            void setup() override;
            void render() override;
    };
} 
