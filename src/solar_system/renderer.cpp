#include "renderer.hpp"
#include "../geometry/sphere/sphere.hpp"
#include <glad/glad.h>
#include "data.hpp"
#include <iostream>

GLuint planetBuffer(){
    const SphereInfo sphereInfo = getSphereInfo({
        {0.0f, 0.0f, 0.0f},
        1.0f,
        40,
        40
    });

    GLuint VBO;

    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glBufferData(
        GL_ARRAY_BUFFER,
        sphereInfo.vertices.size() * sizeof(float),
        sphereInfo.vertices.data(),
        GL_STATIC_DRAW
    );

    return VBO;
}

void renderSolarSystem(GLuint VBO){
    for (std::size_t i = 0; i < celestialBodies.size(); i++) {
        std::cout << celestialBodies[i].name;
    }
}