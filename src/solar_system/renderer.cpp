#include "renderer.hpp"
#include "../geometry/sphere/sphere.hpp"
#include "data.hpp"
#include "bodies/state.hpp"

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>


GLuint planetBuffer()
{
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

void renderSolarSystem(GLuint VBO, GLint modelLocation)
{
    const SphereInfo sphereInfo = getSphereInfo({
        {0.0f, 0.0f, 0.0f},
        1.0f,
        40,
        40
    });

    for (std::size_t i = 0; i < celestialBodyStates.size(); i++)
    {
        const CelestialBodyState& state = celestialBodyStates[i];
        const CelestialBody& body = celestialBodies[i];

        glm::mat4 model = glm::translate(
            glm::mat4(1.0f),
            state.position
        );

        model = glm::scale(
            model,
            glm::vec3(body.radius)
        );

        glUniformMatrix4fv(
            modelLocation,
            1,
            GL_FALSE,
            &model[0][0]
        );

        glDrawArrays(
            GL_TRIANGLES,
            0,
            sphereInfo.vertexCount
        );
    }
}