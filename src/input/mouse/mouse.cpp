#include "mouse.hpp"

#include <iostream>

void processMouseInput(GLFWwindow* window)
{
    static bool isDragging = false;

    static double previousX = 0.0;
    static double previousY = 0.0;

    double currentX;
    double currentY;

    glfwGetCursorPos(window, &currentX, &currentY);

    bool isLeftPressed =
        glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS;

    if (isLeftPressed && !isDragging)
    {
        isDragging = true;

        previousX = currentX;
        previousY = currentY;

        std::cout << "Mouse Down: (" << currentX << ", " << currentY << ")\n";
    }

    if (isDragging)
    {
        double deltaX = currentX - previousX;
        double deltaY = currentY - previousY;

        if (deltaX != 0.0 || deltaY != 0.0)
        {
            std::cout
                << "Move: ("
                << currentX << ", "
                << currentY << ") "
                << "Delta: ("
                << deltaX << ", "
                << deltaY << ")"
                << '\n';

            previousX = currentX;
            previousY = currentY;
        }
    }

    if (!isLeftPressed && isDragging)
    {
        isDragging = false;

        std::cout << "Mouse Up: (" << currentX << ", " << currentY << ")\n";
    }
}