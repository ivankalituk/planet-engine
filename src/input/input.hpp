#pragma once

#include <GLFW/glfw3.h>

#include "../camera/camera.hpp"

void processInput(
    GLFWwindow* window,
    double deltaTime,
    Camera& camera
);

void scrollCallback(
    GLFWwindow* window,
    double xOffset,
    double yOffset
);