#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "geometry/sphere/sphere.hpp"
#include "graphics/shaders.hpp"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


void framebufferSizeCallback(
    GLFWwindow* window,
    int width,
    int height
)
{
    glViewport(0, 0, width, height);
}


int main()
{
    glm::mat4 model = glm::mat4(1.0f);

    glm::mat4 view = glm::lookAt(
        glm::vec3(0.0f, 0.0f, 3.0f),
        glm::vec3(0.0f, 0.0f, 0.0f),
        glm::vec3(0.0f, 1.0f, 0.0f)
    );

    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_DEPTH_BITS, 24);

    GLFWwindow* window = glfwCreateWindow(
        400,
        600,
        "Planet Engine",
        nullptr,
        nullptr
    );

    glfwMakeContextCurrent(window);

    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

    glfwSetFramebufferSizeCallback(
        window,
        framebufferSizeCallback
    );


    // -------------------------
    // Shaders
    // -------------------------

    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);

    glShaderSource(
        vertexShader,
        1,
        &vertexShaderSource,
        nullptr
    );

    glCompileShader(vertexShader);


    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

    glShaderSource(
        fragmentShader,
        1,
        &fragmentShaderSource,
        nullptr
    );

    glCompileShader(fragmentShader);


    unsigned int shaderProgram = glCreateProgram();

    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);

    glLinkProgram(shaderProgram);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);


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