#pragma once
#include <string>
#include <fstream>
#include <filesystem>
#include <GL/glew.h>

namespace pgfm
{
    class BaseRenderer {
        protected:
            std::filesystem::path shadersPath = "shaders";

        public:
            virtual ~BaseRenderer() = default;
            virtual void setup() = 0;
            virtual void render() = 0;
            std::string loadShader(std::string name);
    };
} 
