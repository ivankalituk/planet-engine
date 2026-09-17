#include "input.hpp"

#include <cmath>
#include <iostream>

void processInput(GLFWwindow* window, double deltaTime, Camera& camera)
{
    constexpr float speed = 1.0f;

    if (
        glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS ||
        glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS
        )
    {
        glm::vec3 currentPosition = camera.getPosition();

        float angle = speed * static_cast<float>(deltaTime);

        glm::vec3 newPosition;

        newPosition.x =
            currentPosition.x * std::cos(angle) +
            currentPosition.z * std::sin(angle);

        newPosition.y = currentPosition.y;

        newPosition.z =
            -currentPosition.x * std::sin(angle) +
            currentPosition.z * std::cos(angle);

        camera.move(newPosition - currentPosition);

        std::cout << glm::length(camera.getPosition()) << '\n';
    }

    if (
        glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS ||
        glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS
        )
    {
        glm::vec3 currentPosition = camera.getPosition();

        float angle = -speed * static_cast<float>(deltaTime);

        glm::vec3 newPosition;

        newPosition.x =
            currentPosition.x * std::cos(angle) +
            currentPosition.z * std::sin(angle);

        newPosition.y = currentPosition.y;

        newPosition.z =
            -currentPosition.x * std::sin(angle) +
            currentPosition.z * std::cos(angle);

        camera.move(newPosition - currentPosition);

        std::cout << glm::length(camera.getPosition()) << '\n';
    }
}