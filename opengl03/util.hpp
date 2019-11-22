#pragma once
#include <string>
#include <filesystem>
#include <fstream>

namespace pgfm {
    class Util {
        public:
            static std::string loadShader(std::filesystem::path name);
    };
}
