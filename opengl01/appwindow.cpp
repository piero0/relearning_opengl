#include "appwindow.hpp"

// mock spdlog for now

namespace output {
    void info(std::string txt) {
        std::cout << txt << std::endl;
    }
    void error(std::string txt) {
        std::cout << txt << std::endl;
    }
}

namespace spdlog = output;
using namespace pgfm;

void AppWindow::init_logging() {
    // spdlog::set_default_logger(spdlog::basic_logger_mt("AppWindow", this->title + ".log"));
    // spdlog::set_level(spdlog::level::info);
}

bool AppWindow::init() {
    this->init_logging();

    spdlog::info("logging initialized");

    if(!glfwInit()) {
        return false;
    }

    this->window = glfwCreateWindow(this->width, this->height, this->title.c_str(), nullptr, nullptr);

    if(!this->window) {
        glfwTerminate();
        return false;
    }

    spdlog::info("init done");
    return true;
}

AppWindow::AppWindow(): 
    window(nullptr), width(800), height(600), title("AppWindow") {}

AppWindow::AppWindow(std::string Title, int Width, int Height):
    window(nullptr), width(Width), height(Height), title(Title) {}

AppWindow::~AppWindow() {
    if(this->window) {
        glfwDestroyWindow(this->window);
        spdlog::info("Window destroyed");
    }
    glfwTerminate();
    spdlog::info("GLFW terminated");
}

void AppWindow::setRenderer(std::unique_ptr<Renderer> renderer) {
    this->renderer = std::move(renderer);
}

void AppWindow::main() {
    if(!this->init()) {
        return;
    }

    glfwMakeContextCurrent(this->window);

    if(glewInit() != GLEW_OK) {
        spdlog::error("GLEW init failed");
        return;
    }

    glfwSwapInterval(1); //vsync on

    std::string txt = "OpenGL Version: " + std::to_string(glfwGetWindowAttrib(this->window, GLFW_CONTEXT_VERSION_MAJOR)) + "." + 
        std::to_string(glfwGetWindowAttrib(this->window, GLFW_CONTEXT_VERSION_MINOR));

    spdlog::info(txt);

    if(this->renderer == nullptr) {
        spdlog::error("Renderer not set");
        return;
    }

    this->renderer->setup();

    while(!glfwWindowShouldClose(this->window)) {
        this->renderer->render();
        glfwSwapBuffers(this->window);
        glfwPollEvents();
    }
}