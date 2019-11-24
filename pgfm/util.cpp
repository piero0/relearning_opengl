#include "util.hpp"

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
