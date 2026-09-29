#include "renderer.hpp"
#include "../../geometry/sphere/sphere.hpp"
#include "../data/data.hpp"
#include "../bodies/state.hpp"
#include "../types.hpp"

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

    glVertexAttribPointer(
        0,
        3,
        GL_FLOAT,
        GL_FALSE,
        4 * sizeof(float),
        (void*)0
    );

    glEnableVertexAttribArray(0);

    glVertexAttribPointer(
        1,
        1,
        GL_FLOAT,
        GL_FALSE,
        4 * sizeof(float),
        (void*)(3 * sizeof(float))
    );

    glEnableVertexAttribArray(1);

    return VBO;
}

void renderSolarSystem(
    GLuint VBO,
    GLint modelLocation,
    GLint primaryColorLocation,
    GLint secondaryColorLocation,
    float deltaTime
)
{
    const SphereInfo sphereInfo = getSphereInfo({
        {0.0f, 0.0f, 0.0f},
        1.0f,
        40,
        40
        });

    updateCelestialBodies(deltaTime);

    for (std::size_t i = 0; i < celestialBodyStates.size(); i++)
    {
        const CelestialBodyState& state =
            celestialBodyStates[i];

        const CelestialBody& body =
            celestialBodies[i];

        glm::mat4 model = glm::translate(
            glm::mat4(1.0f),
            state.position
        );

        glm::vec3 localYAxis = {
            0.0f,
            1.0f,
            0.0f
        };

        glm::vec3 rotationAxis =
            glm::normalize(body.rotationAxis);

        float dotProduct =
            glm::dot(localYAxis, rotationAxis);

        // local axis rotation
        if (dotProduct < 0.9999f)
        {
            glm::vec3 tiltAxis =
                glm::normalize(
                    glm::cross(
                        localYAxis,
                        rotationAxis
                    )
                );

            float tiltAngle =
                glm::acos(dotProduct);

            model = glm::rotate(
                model,
                tiltAngle,
                tiltAxis
            );
        }

        // whole planet rotation in a local axis
        model = glm::rotate(
            model,
            glm::radians(state.rotationAngle),
            glm::vec3(0.0f, 1.0f, 0.0f)
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

        glUniform3fv(
            primaryColorLocation,
            1,
            &body.primaryColor[0]
        );

        glUniform3fv(
            secondaryColorLocation,
            1,
            &body.secondaryColor[0]
        );

        glDrawArrays(
            GL_TRIANGLES,
            0,
            sphereInfo.vertexCount
        );
    }
}