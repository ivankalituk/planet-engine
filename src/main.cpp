#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "camera/camera.hpp"
#include "geometry/sphere/sphere.hpp"
#include "graphics/shaders.hpp"
#include "window/window.hpp"

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


    // -------------------------
    // Shaders
    // -------------------------

    unsigned int shaderProgram = createShaderProgram();


    // -------------------------
    // Uniform locations
    // -------------------------

    int modelLocation = glGetUniformLocation(
        shaderProgram,
        "model"
    );

    int viewLocation = glGetUniformLocation(
        shaderProgram,
        "view"
    );

    int projectionLocation = glGetUniformLocation(
        shaderProgram,
        "projection"
    );


    // -------------------------
    // Camera
    // -------------------------

    Camera camera;


    // -------------------------
    // Model
    // -------------------------

    glm::mat4 model = glm::mat4(1.0f);


    // -------------------------
    // Sphere
    // -------------------------

    const SphereInfo sphereInfo = getSphereInfo({
        {0.0f, 0.0f, 0.0f},
        1.0f,
        40,
        40
        });


    // -------------------------
    // Buffers
    // -------------------------

    unsigned int VAO;
    unsigned int VBO;

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glBufferData(
        GL_ARRAY_BUFFER,
        sphereInfo.vertices.size() * sizeof(float),
        sphereInfo.vertices.data(),
        GL_STATIC_DRAW
    );


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

    glEnable(GL_DEPTH_TEST);


    // -------------------------
    // Render loop
    // -------------------------

    while (!glfwWindowShouldClose(window))
    {
        int width;
        int height;

        glfwGetFramebufferSize(
            window,
            &width,
            &height
        );

        glm::mat4 projection = glm::perspective(
            glm::radians(45.0f),
            static_cast<float>(width) /
            static_cast<float>(height),
            0.1f,
            100.0f
        );

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

        glDrawArrays(
            GL_TRIANGLES,
            0,
            sphereInfo.vertexCount
        );


        glfwSwapBuffers(window);
        glfwPollEvents();
    }


    // -------------------------
    // Cleanup
    // -------------------------

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteProgram(shaderProgram);

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}