#include "appwindow.hpp"

int main() {
    auto app = pgfm::AppWindow("OpenGL01", 800, 600);
    app.setRenderer(std::make_unique<pgfm::SimpleRenderer>());
    app.main();
}