#pragma once
#include <GL/glew.h>

namespace pgfm
{
    class Renderer {
        public:
            virtual void setup() = 0;
            virtual void render() = 0;
    };

    class SimpleRenderer: public Renderer {
        private:
            GLuint shaderProgram;

        public:
            void setup() override;
            void render() override;
    };
} 
