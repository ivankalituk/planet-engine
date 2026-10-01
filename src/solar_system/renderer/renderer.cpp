#include "renderer.hpp"
#include "../../geometry/sphere/sphere.hpp"
#include "../data/data.hpp"
#include "../bodies/state.hpp"
#include "../types.hpp"
#include "../../geometry/lineCircle/lineCircle.hpp"

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>


GLuint planetBuffer() {
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

GLuint orbitBuffer() {
    const LineCircleInfo orbitInfo = getLineCircleInfo({
        {0.0f, 0.0f, 0.0f},
        1.0f,
        30
        });

    GLuint VBO;

    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glBufferData(
        GL_ARRAY_BUFFER,
        orbitInfo.vertices.size() * sizeof(float),
        orbitInfo.vertices.data(),
        GL_STATIC_DRAW
    );

    return VBO;
}

GLuint createPlanetVAO(GLuint VBO) {
    GLuint VAO;

    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);

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

    glBindVertexArray(0);

    return VAO;
}

GLuint createOrbitVAO(GLuint VBO) {
    GLuint VAO;

    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glVertexAttribPointer(
        0,
        3,
        GL_FLOAT,
        GL_FALSE,
        3 * sizeof(float),
        (void*)0
    );

    glEnableVertexAttribArray(0);

    glBindVertexArray(0);

    return VAO;
}

void renderSolarSystem(
    GLint modelLocation,
    GLint primaryColorLocation,
    GLint secondaryColorLocation,
    GLint orbitColorLocation,
    GLint isOrbitLocation,
    GLuint planetVAO,
    GLuint orbitVAO,
    float deltaTime
) {
    const SphereInfo sphereInfo = getSphereInfo({
        {0.0f, 0.0f, 0.0f},
        1.0f,
        40,
        40
        });

    for (std::size_t i = 0; i < celestialBodyStates.size(); i++) {

        // Planet orbit
        if (celestialBodyStates[i].parentId == "STAR") {
            glBindVertexArray(orbitVAO);

            glm::vec3 orbitColor = glm::vec3(0.35f);

            glUniform3fv(
                orbitColorLocation,
                1,
                &orbitColor[0]
            );

            glUniform1i(
                isOrbitLocation,
                true
            );

            glm::mat4 orbitModel = glm::scale(
                glm::mat4(1.0f),
                glm::vec3(celestialBodies[i].distanceFromParent)
            );

            glUniformMatrix4fv(
                modelLocation,
                1,
                GL_FALSE,
                &orbitModel[0][0]
            );

            glDrawArrays(
                GL_LINE_LOOP,
                0,
                30
            );
        }

        // Satellite orbits
        for (std::size_t s = 0; s < celestialBodyStates.size(); s++) {

            if (celestialBodyStates[s].parentId == celestialBodyStates[i].id) {

                glBindVertexArray(orbitVAO);

                glm::vec3 orbitColor = glm::vec3(0.18f);

                glUniform3fv(
                    orbitColorLocation,
                    1,
                    &orbitColor[0]
                );

                glUniform1i(
                    isOrbitLocation,
                    true
                );

                glm::vec3 localYAxis = {
                    0.0f,
                    1.0f,
                    0.0f
                };

                glm::vec3 orbitAxis =
                    glm::normalize(celestialBodyStates[i].orbitAxis);

                float dotProduct =
                    glm::dot(localYAxis, orbitAxis);

                glm::mat4 orbitModel = glm::translate(
                    glm::mat4(1.0f),
                    celestialBodyStates[i].position
                );

                if (dotProduct < 0.9999f)
                {
                    glm::vec3 tiltAxis =
                        glm::normalize(
                            glm::cross(
                                localYAxis,
                                orbitAxis
                            )
                        );

                    float tiltAngle =
                        glm::acos(dotProduct);

                    orbitModel = glm::rotate(
                        orbitModel,
                        tiltAngle,
                        tiltAxis
                    );
                }

                orbitModel = glm::scale(
                    orbitModel,
                    glm::vec3(
                        celestialBodies[s].distanceFromParent
                    )
                );

                glUniformMatrix4fv(
                    modelLocation,
                    1,
                    GL_FALSE,
                    &orbitModel[0][0]
                );

                glDrawArrays(
                    GL_LINE_LOOP,
                    0,
                    30
                );
            }
        }

        // Planets
        glBindVertexArray(planetVAO);

        glUniform1i(
            isOrbitLocation,
            false
        );

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

        model = glm::rotate(
            model,
            glm::radians(state.selfRotationAngle),
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