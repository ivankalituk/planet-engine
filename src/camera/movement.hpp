#pragma once

#include <GLFW/glfw3.h>

#include "../camera/camera.hpp"

constexpr float speed = 1.0f;
constexpr float zoomSpeed = 0.05f;

void processCameraMovement(GLFWwindow* window, double deltaTime, Camera& camera);