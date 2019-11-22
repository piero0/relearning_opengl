#pragma once
#include <GL/glew.h>

namespace pgfm
{
    class BaseRenderer {
        public:
            virtual ~BaseRenderer() = default;
            virtual void setup() = 0;
            virtual void render() = 0;
    };
} 
