#include <memory>
#include <string>
#include <iostream>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <GLFW/glfw3.h>

class AppWindow {
    private:
        GLFWwindow* window;
        int width, height;
        std::string title;

        void init_logging() {
            spdlog::set_default_logger(spdlog::basic_logger_mt("AppWindow", this->title + ".log"));
            spdlog::set_level(spdlog::level::info);
        }

        bool init() {
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

    public:
        AppWindow(): 
            window(nullptr), width(800), height(600), title("AppWindow") {}

        AppWindow(std::string Title, int Width, int Height):
            window(nullptr), width(Width), height(Height), title(Title) {}

        ~AppWindow() {
            if(this->window) {
                glfwDestroyWindow(this->window);
                spdlog::info("Window destroyed");
            }
            glfwTerminate();
            spdlog::info("GLFW terminated");
        }

        void main() {
            if(!this->init()) {
                return;
            }

            glfwMakeContextCurrent(this->window);
            glfwSwapInterval(1); //vsync on

            while(!glfwWindowShouldClose(this->window)) {
                glClear(GL_COLOR_BUFFER_BIT);
                glfwSwapBuffers(this->window);
                glfwPollEvents();
            }
        }
};

int main() {
    auto app = AppWindow("OpenGL01", 800, 600);
    app.main();
}