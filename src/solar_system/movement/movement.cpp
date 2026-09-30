#include "movement.hpp"
#include <iostream>
#include "../bodies/state.hpp"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

void processPlanetsMovement(GLFWwindow* window, double deltaTime) {

    glm::vec3 sunOrbitAxis = celestialBodyStates[0].orbitAxis;

    if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS) {


        for (int i = 0; celestialBodyStates.size() > i; i++) {
            if (celestialBodyStates[i].id != "STAR" && celestialBodyStates[i].parentId == "STAR") {
                float deltaAngle = celestialBodyStates[i].orbitRotationAngle * deltaTime;
                glm::mat4 rotation = glm::rotate(glm::mat4(1.0f), glm::radians(deltaAngle), sunOrbitAxis);

                glm::vec4 newPosition = rotation * glm::vec4(celestialBodyStates[i].position, 1.0f);


                for (int s = 0; celestialBodyStates.size() > s; s++) {
                    if (celestialBodyStates[s].parentId == celestialBodyStates[i].id) {
                    }
                }

                celestialBodyStates[i].position = glm::vec3(newPosition);
            }
        }
    }
}