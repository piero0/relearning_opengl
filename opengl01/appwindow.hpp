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
            GLFWwindow* window;
            int width, height;
            std::string title;
            std::unique_ptr<Renderer> renderer;

            void init_logging();
            bool init();

        public:
            AppWindow();
            AppWindow(std::string Title, int Width, int Height);
            ~AppWindow();

            void main();
            void setRenderer(std::unique_ptr<Renderer> renderer);
    };
}
