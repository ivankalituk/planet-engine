#include "scroll.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>
#include "../../camera/camera.hpp"

constexpr float zoomSpeed = 0.05f;

void scrollCallback(
    GLFWwindow* window,
    double xOffset,
    double yOffset
)
{
    Camera* camera =
        static_cast<Camera*>(
            glfwGetWindowUserPointer(window)
            );

    if (yOffset > 0) {
        camera->zoom(
            zoomSpeed
        );
    }

    if (yOffset < 0) {
        camera->zoom(
            -zoomSpeed
        );
    }
}