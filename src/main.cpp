#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "camera/camera.hpp"
#include "geometry/sphere/sphere.hpp"
#include "graphics/shaders.hpp"
#include "window/window.hpp"
#include "input/keyboard/keyboard.hpp"
#include "input/scroll/scroll.hpp"
#include "solar_system/renderer/renderer.hpp"
#include "solar_system/bodies/state.hpp"

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

    int modelLocation =
        glGetUniformLocation(
            shaderProgram,
            "model"
        );

    int viewLocation =
        glGetUniformLocation(
            shaderProgram,
            "view"
        );

    int projectionLocation =
        glGetUniformLocation(
            shaderProgram,
            "projection"
        );

    int primaryColorLocation =
        glGetUniformLocation(
            shaderProgram,
            "primaryColor"
        );

    int secondaryColorLocation =
        glGetUniformLocation(
            shaderProgram,
            "secondaryColor"
        );

    int orbitColorLocation =
        glGetUniformLocation(
            shaderProgram,
            "orbitColor"
        );

    int isOrbitLocation =
        glGetUniformLocation(
            shaderProgram,
            "isOrbit"
        );

    Camera camera;

    glm::mat4 model = glm::mat4(1.0f);

    // -------------------------
    // VBO buffer and VAO
    // -------------------------

    GLuint planetVBO = planetBuffer();
    GLuint orbitVBO = orbitBuffer();

    GLuint planetVAO = createPlanetVAO(planetVBO);
    GLuint orbitVAO = createOrbitVAO(orbitVBO);

    glEnable(GL_DEPTH_TEST);

    glEnable(GL_BLEND);
    glBlendFunc(
        GL_SRC_ALPHA,
        GL_ONE_MINUS_SRC_ALPHA
    );

    double previousTime = glfwGetTime();

    createCelestialBodyStates();

    glfwSwapInterval(0);

    while (!glfwWindowShouldClose(window))
    {
        double currentTime = glfwGetTime();

        double deltaTime =
            currentTime - previousTime;

        previousTime = currentTime;

        processInput(
            window,
            deltaTime,
            camera
        );

        int width;
        int height;

        glfwGetFramebufferSize(
            window,
            &width,
            &height
        );

        glfwSetWindowUserPointer(
            window,
            &camera
        );

        glfwSetScrollCallback(
            window,
            scrollCallback
        );

        glm::mat4 projection = glm::perspective(
            glm::radians(45.0f),
            static_cast<float>(width) /
            static_cast<float>(height),
            0.1f,
            100.0f
        );

        glm::mat4 view =
            camera.getViewMatrix();

        glClearColor(
            0.008f,
            0.004f,
            0.012f,
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

        glBindVertexArray(planetVAO);

        renderSolarSystem(
            modelLocation,
            primaryColorLocation,
            secondaryColorLocation,
            orbitColorLocation,
            isOrbitLocation,
            planetVAO,
            orbitVAO,
            deltaTime
        );

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // -------------------------
    // Cleanup
    // -------------------------

    glDeleteVertexArrays(
        1,
        &planetVAO
    );

    glDeleteVertexArrays(
        1,
        &orbitVAO
    );

    glDeleteBuffers(
        1,
        &planetVBO
    );

    glDeleteBuffers(
        1,
        &orbitVBO
    );

    glDeleteProgram(
        shaderProgram
    );

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}