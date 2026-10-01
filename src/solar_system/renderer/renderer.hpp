#pragma once

#include <glad/glad.h>

GLuint planetBuffer();

GLuint orbitBuffer();

void renderSolarSystem(
    GLint modelLocation,
    GLint primaryColorLocation,
    GLint secondaryColorLocation,
    float deltaTime
);