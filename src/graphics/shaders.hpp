#pragma once


const char* fragmentShaderSource = R"(
    #version 330 core

    in vec3 color;

    out vec4 FragColor;

    void main()
    {
        FragColor = vec4(color, 1.0);
    }
)";

const char* vertexShaderSource = R"(
    #version 330 core

    layout (location = 0) in vec3 aPos;
    layout (location = 1) in vec3 aColor;

    out vec3 color;

    void main()
    {
        float angleY = 0.6;
        float angleX = 0.4;

        float x = aPos.x;
        float y = aPos.y;
        float z = aPos.z;

        // Поворот вокруг Y
        float rotatedX = x * cos(angleY) + z * sin(angleY);
        float rotatedZ = -x * sin(angleY) + z * cos(angleY);

        // Поворот вокруг X
        float finalY = y * cos(angleX) - rotatedZ * sin(angleX);
        float finalZ = y * sin(angleX) + rotatedZ * cos(angleX);

        gl_Position = vec4(
            rotatedX,
            finalY,
            finalZ,
            1.0
        );

        color = aColor;
    }
)";