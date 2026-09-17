#include "input.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include <cmath>

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
    }

    if (
        glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS ||
        glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS
        )
    {
        glm::vec3 currentPosition = camera.getPosition();

        float angle = speed * static_cast<float>(deltaTime);

        glm::vec3 right = camera.getRight();

        glm::vec3 newPosition =
            glm::rotate(
                glm::mat4(1.0f),
                angle,
                right
            ) * glm::vec4(currentPosition, 1.0f);

        camera.move(newPosition - currentPosition);
    }

    if (
        glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS ||
        glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS
        )
    {
        glm::vec3 currentPosition = camera.getPosition();

        float angle = -speed * static_cast<float>(deltaTime);

        glm::vec3 right = camera.getRight();

        glm::vec3 newPosition =
            glm::rotate(
                glm::mat4(1.0f),
                angle,
                right
            ) * glm::vec4(currentPosition, 1.0f);

        camera.move(newPosition - currentPosition);
    }
}