#pragma once

#include <glad/glad.h>

GLuint planetBuffer();
GLuint orbitBuffer();

GLuint createPlanetVAO(GLuint VBO);
GLuint createOrbitVAO(GLuint VBO);

void renderSolarSystem(
    GLint modelLocation,
    GLint primaryColorLocation,
    GLint secondaryColorLocation,
    float deltaTime
);