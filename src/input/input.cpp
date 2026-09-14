#include "input.hpp"

#include <iostream>

void processInput(GLFWwindow* window)
{
    static bool wasPressed = false;

    bool isPressed =
        glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS;

    if (wasPressed && !isPressed)
    {
        std::cout << "W released" << std::endl;
    }

    wasPressed = isPressed;



    static bool wasPressedS = false;

    bool isPressedS = glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS;

    if (isPressedS && !wasPressedS) {
        std::cout << "S pressed" << std::endl;
    }

    wasPressedS = isPressedS;



    bool isWPressed = glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS;
    bool isShiftPressed = glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS;
    static bool wasBindPressed = false;


    if (isWPressed && isShiftPressed && !wasBindPressed)
    {
        std::cout << "Shift + W" << std::endl;
    }

    wasBindPressed = isWPressed && isShiftPressed;
}