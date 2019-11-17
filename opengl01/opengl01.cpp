#include "appwindow.hpp"

int main() {
    auto app = pgfm::AppWindow("OpenGL01", 800, 600);
    app.setRendererClass<pgfm::SimpleRenderer>();
    app.main();
}