#include "input.hpp"

#include <iostream>

void processInput(GLFWwindow* window, double deltaTime, Camera& camera)
{
    constexpr float speed = 1.0f;

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS || glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
    {
        camera.move(
            glm::vec3(0.0f, speed * deltaTime, 0.0f)
        );
    }

    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS || glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
    {
        camera.move(
            glm::vec3(0.0f, -speed * deltaTime, 0.0f)
        );
    }

    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS || glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
    {
        camera.move(
            glm::vec3(-speed * deltaTime, 0.0f, 0.0f)
        );
    }

    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS || glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
    {
        camera.move(
            glm::vec3(speed * deltaTime, 0.0f, 0.0f)
        );
    }
}