#pragma once

#include <glad/glad.h>

GLuint planetBuffer();

void renderSolarSystem(
    GLuint VBO,
    GLint modelLocation,
    GLint primaryColorLocation,
    GLint secondaryColorLocation,
    float deltaTime
);