#include "util.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

using namespace pgfm;
using namespace std::string_literals;

std::string Util::loadShader(std::filesystem::path name) {
    std::ifstream file(name);

    auto line = ""s;
    auto source = ""s;

    while(std::getline(file, line)) {
        source += line + '\n';
    }

    file.close();

    return source;
}
    
void Image::load(std::filesystem::path filename) {
    this->imageData = stbi_load(filename.c_str(), &this->width, &this->height, &this->channels, 0);
}

Image::~Image() {
    if(this->imageData != nullptr) {
        stbi_image_free(this->imageData);
    }
}
