#include "baserenderer.hpp"

using namespace pgfm;
using namespace std::string_literals;

std::string BaseRenderer::loadShader(std::string name) {
    std::ifstream file(this->shadersPath / name);

    auto line = ""s;
    auto source = ""s;

    while(std::getline(file, line)) {
        source += line + '\n';
    }

    file.close();

    return source;
}
