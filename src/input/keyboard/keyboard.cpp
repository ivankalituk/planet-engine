#include "keyboard.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>
#include "../../camera/movement.hpp"

void processInput(GLFWwindow* window, double deltaTime, Camera& camera) {
	processCameraMovement(window, deltaTime, camera);


    if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS) {
        
    }

}