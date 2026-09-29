#include "keyboard.hpp"
#include "../../camera/movement.hpp"
#include "../../solar_system/movement/movement.hpp"


void processInput(GLFWwindow* window, double deltaTime, Camera& camera) {
	processCameraMovement(window, deltaTime, camera);


	processPlanetsMovement(window, deltaTime);

}