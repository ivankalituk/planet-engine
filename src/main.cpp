#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "camera/camera.hpp"
#include "geometry/sphere/sphere.hpp"
#include "graphics/shaders.hpp"
#include "window/window.hpp"
#include "input/keyboard/keyboard.hpp"
#include "input/scroll/scroll.hpp"
#include "input/mouse/mouse.hpp"
#include "solar_system/renderer.hpp"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

int main()
{
    GLFWwindow* window = createWindow(
        400,
        600,
        "Planet Engine"
    );

    unsigned int shaderProgram = createShaderProgram();

    int modelLocation = glGetUniformLocation(shaderProgram, "model");
    int viewLocation = glGetUniformLocation(shaderProgram, "view");
    int projectionLocation = glGetUniformLocation(shaderProgram, "projection");

    Camera camera;

    glm::mat4 model = glm::mat4(1.0f);

    // -------------------------
    // Buffers
    // -------------------------

    GLuint VAO;
    GLuint VBO = planetBuffer();

    glGenVertexArrays(1, &VAO);

    // ВАЖНО: сначала привязываем VAO и VBO
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    // Position
    glVertexAttribPointer(
        0,
        3,
        GL_FLOAT,
        GL_FALSE,
        6 * sizeof(float),
        (void*)0
    );

    glEnableVertexAttribArray(0);

    // Color
    glVertexAttribPointer(
        1,
        3,
        GL_FLOAT,
        GL_FALSE,
        6 * sizeof(float),
        (void*)(3 * sizeof(float))
    );

    glEnableVertexAttribArray(1);

    glBindVertexArray(0);

    glEnable(GL_DEPTH_TEST);

    double previousTime = glfwGetTime();

    while (!glfwWindowShouldClose(window))
    {
        double currentTime = glfwGetTime();
        double deltaTime = currentTime - previousTime;
        previousTime = currentTime;

        processInput(window, deltaTime, camera);

        int width;
        int height;

        glfwGetFramebufferSize(window, &width, &height);

        glfwSetWindowUserPointer(window, &camera);
        glfwSetScrollCallback(window, scrollCallback);

        glm::mat4 projection = glm::perspective(
            glm::radians(45.0f),
            static_cast<float>(width) / static_cast<float>(height),
            0.1f,
            100.0f
        );

        processMouseInput(window, camera, projection);

        glm::mat4 view = camera.getViewMatrix();

        glClearColor(
            0.2f,
            0.4f,
            0.8f,
            1.0f
        );

        glClear(
            GL_COLOR_BUFFER_BIT |
            GL_DEPTH_BUFFER_BIT
        );

        glUseProgram(shaderProgram);

        glUniformMatrix4fv(
            modelLocation,
            1,
            GL_FALSE,
            glm::value_ptr(model)
        );

        glUniformMatrix4fv(
            viewLocation,
            1,
            GL_FALSE,
            glm::value_ptr(view)
        );

        glUniformMatrix4fv(
            projectionLocation,
            1,
            GL_FALSE,
            glm::value_ptr(projection)
        );

        glBindVertexArray(VAO);

        renderSolarSystem(VBO, modelLocation);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteProgram(shaderProgram);

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}