#include "movement.hpp"
#include <iostream>
#include "../bodies/state.hpp"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

void processPlanetsMovement(GLFWwindow* window, double deltaTime) {

    glm::vec3 sunOrbitAxis = celestialBodyStates[0].orbitAxis;

    static double accelerationTimer = 0.0;
    static double accelerationFactor = 1.0;

    if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS) {

        accelerationTimer += deltaTime;

        if (accelerationTimer > 2.0 && accelerationFactor <= 6) {
            accelerationFactor += 0.01;
        }

        double transition = accelerationFactor * deltaTime;

        for (int i = 0; celestialBodyStates.size() > i; i++) {

            //planets self rotation
            celestialBodyStates[i].selfRotationAngle +=
                celestialBodyStates[i].selfRotationSpeed * transition;


            //planets movement
            if (celestialBodyStates[i].id != "STAR" && celestialBodyStates[i].parentId == "STAR") {
                float deltaAngle = celestialBodyStates[i].orbitRotationAngle * transition;
                glm::mat4 rotation = glm::rotate(glm::mat4(1.0f), glm::radians(deltaAngle), sunOrbitAxis);

                glm::vec4 newPosition = rotation * glm::vec4(celestialBodyStates[i].position, 1.0f);


                for (int s = 0; celestialBodyStates.size() > s; s++) {
                    if (celestialBodyStates[s].parentId == celestialBodyStates[i].id) {
                        glm::vec3 planetMovement = glm::vec3(newPosition) - celestialBodyStates[i].position;

                        float deltaAngle = celestialBodyStates[s].orbitRotationAngle * transition;

                        glm::mat4 satelliteRotation = glm::rotate(
                            glm::mat4(1.0f),
                            glm::radians(deltaAngle),
                            celestialBodyStates[i].orbitAxis
                        );

                        glm::vec3 relativePosition = celestialBodyStates[s].position - celestialBodyStates[i].position;
                        glm::vec4 newRelativePosition = satelliteRotation * glm::vec4(relativePosition, 1.0f);
                        glm::vec3 newSatellitePosition = glm::vec3(newPosition) + glm::vec3(newRelativePosition);

                        celestialBodyStates[s].position = newSatellitePosition;
                    }
                }

                celestialBodyStates[i].position = glm::vec3(newPosition);
            }
        }
    } else {
        accelerationTimer = 0.0;
        accelerationFactor = 1.0;
    }
}