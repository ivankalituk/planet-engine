#include "input.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>


constexpr float speed = 1.0f;
constexpr float zoomSpeed = 0.05f;

void processInput(GLFWwindow* window, double deltaTime, Camera& camera)
{

    float angle =
        speed * static_cast<float>(deltaTime);

    if (
        glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS ||
        glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS
        )
    {
        camera.rotate(
            angle,
            glm::vec3(0.0f, 1.0f, 0.0f)
        );
    }

    if (
        glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS ||
        glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS
        )
    {
        camera.rotate(
            -angle,
            glm::vec3(0.0f, 1.0f, 0.0f)
        );
    }

    if (
        glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS ||
        glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS
        )
    {
        camera.rotate(
            angle,
            camera.getRight()
        );
    }

    if (
        glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS ||
        glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS
        )
    {
        camera.rotate(
            -angle,
            camera.getRight()
        );
    }

    if (glfwGetKey(window, GLFW_KEY_Z) == GLFW_PRESS)
    {
        {
            camera.zoom(zoomSpeed);
        }
    }

    if (
        glfwGetKey(window, GLFW_KEY_X) == GLFW_PRESS
        )
    {
        camera.zoom(-zoomSpeed);
    }
}

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