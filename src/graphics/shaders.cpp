#include "shaders.hpp"
#include <glad/glad.h>

namespace
{
    const char* fragmentShaderSource = R"(
        #version 330 core

        in float colorIndex;

        out vec4 FragColor;

        uniform vec3 primaryColor;
        uniform vec3 secondaryColor;

        uniform vec3 orbitColor;
        uniform bool isOrbit;

        void main()
        {
            if (isOrbit)
            {
                FragColor = vec4(orbitColor, 0.4);
            }
            else if (colorIndex < 0.5)
            {
                FragColor = vec4(primaryColor, 1.0);
            }
            else
            {
                FragColor = vec4(secondaryColor, 1.0);
            }
        }
    )";


    const char* vertexShaderSource = R"(
        #version 330 core

        layout (location = 0) in vec3 aPos;
        layout (location = 1) in float aColorIndex;

        out float colorIndex;

        uniform mat4 model;
        uniform mat4 view;
        uniform mat4 projection;

        void main()
        {
            gl_Position =
                projection *
                view *
                model *
                vec4(aPos, 1.0);

            colorIndex = aColorIndex;
        }
    )";
}

unsigned int createShaderProgram()
{
    unsigned int vertexShader =
        glCreateShader(GL_VERTEX_SHADER);

    glShaderSource(
        vertexShader,
        1,
        &vertexShaderSource,
        nullptr
    );

    glCompileShader(vertexShader);

    unsigned int fragmentShader =
        glCreateShader(GL_FRAGMENT_SHADER);

    glShaderSource(
        fragmentShader,
        1,
        &fragmentShaderSource,
        nullptr
    );

    glCompileShader(fragmentShader);

    unsigned int shaderProgram =
        glCreateProgram();

    glAttachShader(
        shaderProgram,
        vertexShader
    );

    glAttachShader(
        shaderProgram,
        fragmentShader
    );

    glLinkProgram(shaderProgram);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    return shaderProgram;
}