#pragma once

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

GLFWwindow* createWindow(
    int width,
    int height,
    const char* title
);