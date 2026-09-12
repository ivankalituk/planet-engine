#include "window.hpp"

#include <glad/glad.h>

namespace
{
    void framebufferSizeCallback(
        GLFWwindow* window,
        int width,
        int height
    )
    {
        glViewport(0, 0, width, height);
    }
}

GLFWwindow* createWindow(
    int width,
    int height,
    const char* title
)
{
    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_DEPTH_BITS, 24);

    GLFWwindow* window = glfwCreateWindow(
        width,
        height,
        title,
        nullptr,
        nullptr
    );

    glfwMakeContextCurrent(window);

    gladLoadGLLoader(
        (GLADloadproc)glfwGetProcAddress
    );

    glfwSetFramebufferSizeCallback(
        window,
        framebufferSizeCallback
    );

    return window;
}