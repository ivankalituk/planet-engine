#pragma once

#include <GLFW/glfw3.h>
#include "../../camera/camera.hpp"
#include <glm/gtc/matrix_transform.hpp>

void processMouseInput(
    GLFWwindow* window,
    const Camera& camera,
    const glm::mat4& projection
);