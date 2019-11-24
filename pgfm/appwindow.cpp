#include "appwindow.hpp"

using namespace pgfm;

void AppWindow::init_logging() {
    spdlog::set_default_logger(spdlog::stdout_color_mt(this->title));
    spdlog::set_level(spdlog::level::info);
    spdlog::info("Logging initialized");
}

bool AppWindow::init() {
    this->init_logging();

    if(!glfwInit()) {
        return false;
    }

    this->window = glfwCreateWindow(this->width, this->height, this->title.c_str(), nullptr, nullptr);

    if(!this->window) {
        glfwTerminate();
        return false;
    }

    spdlog::info("Window init done");
    return true;
}

AppWindow::AppWindow(std::string Title, int Width, int Height):
    width(Width), height(Height), title(Title) {}

AppWindow::~AppWindow() {
    if(this->window) {
        glfwDestroyWindow(this->window);
        spdlog::info("Window destroyed");
    }
    glfwTerminate();
    spdlog::info("GLFW terminated");
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

    spdlog::info("Entering render loop");
    
    while(!glfwWindowShouldClose(this->window)) {
        this->renderer->render();
        glfwSwapBuffers(this->window);
        glfwPollEvents();
    }

    spdlog::info("Quiting app");
}