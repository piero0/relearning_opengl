#include "appwindow.hpp"
#include "renderer.hpp"

int main() {
    auto app = pgfm::AppWindow("OpenGL04", 800, 600);
    app.setRendererClass<SimpleRenderer>();
    app.main();
}