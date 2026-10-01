#pragma once

#include <glad/glad.h>

GLuint planetBuffer();

GLuint orbitBuffer();

void renderSolarSystem(
    GLuint VBO,
    GLint modelLocation,
    GLint primaryColorLocation,
    GLint secondaryColorLocation,
    float deltaTime
);