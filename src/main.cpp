#include <GLFW/glfw3.h>
#include <iostream>

int main()
{
    glfwInit();
    
    GLFWwindow* window = glfwCreateWindow(
        800,
        1200,
        "Planet Engine custom",
        nullptr,
        nullptr
    );

    std::cout << 'n';

    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}