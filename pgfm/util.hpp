#pragma once
#include <string>
#include <filesystem>
#include <fstream>
#include <spdlog/spdlog.h>

namespace pgfm {
    class Util {
        public:
            static std::string loadShader(std::filesystem::path name);
    };

    class Image {
        public:
            unsigned char* imageData = nullptr;
            int width = 0, height = 0, channels = 0;
        
            Image() = default;
            ~Image();

            void load(std::filesystem::path filename);
    };
}
