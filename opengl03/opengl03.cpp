#include "appwindow.hpp"
#include "renderer.hpp"

int main() {
    auto app = pgfm::AppWindow("OpenGL02", 800, 600);
    app.setRendererClass<SimpleRenderer>();
    app.main();
}