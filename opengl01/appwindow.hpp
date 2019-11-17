#pragma once

#include <memory>
#include <string>
#include <iostream>
// #include <spdlog/spdlog.h>
// #include <spdlog/sinks/basic_file_sink.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "renderer.hpp"

namespace pgfm {
    class AppWindow {
        private:
            GLFWwindow* window = nullptr;
            int width = 800, height = 600;
            std::string title = "AppWindow";
            std::unique_ptr<BaseRenderer> renderer;

            void init_logging();
            bool init();

        public:
            AppWindow() = default;
            AppWindow(std::string Title, int Width, int Height);
            ~AppWindow();

            void main();

            template<class T> void setRendererClass() {
                this->renderer = std::make_unique<T>();
            }
    };
}
