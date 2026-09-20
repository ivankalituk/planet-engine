#include "mouse.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>

void processMouseInput(
    GLFWwindow* window,
    const Camera& camera,
    const glm::mat4& projection
)
{
    static bool wasPressed = false;

    static double previousX = 0.0;
    static double previousY = 0.0;

    double currentX;
    double currentY;

    glfwGetCursorPos(window, &currentX, &currentY);

    bool isLeftPressed =
        glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS;

    if (isLeftPressed && !wasPressed)
    {
        previousX = currentX;
        previousY = currentY;

        int width;
        int height;

        glfwGetWindowSize(window, &width, &height);

        // viewport has inverted OY axis, so i make minus height
        glm::vec3 screenPoint(
            static_cast<float>(currentX),
            static_cast<float>(height) - static_cast<float>(currentY),
            0.0f
        );

        glm::vec3 worldPoint = glm::unProject(
            screenPoint,
            camera.getViewMatrix(),
            projection,
            glm::vec4(0.0f, 0.0f, width, height)
        );

        std::cout
            << "World point: ("
            << worldPoint.x << ", "
            << worldPoint.y << ", "
            << worldPoint.z << ")\n";
    }

    wasPressed = isLeftPressed;
}