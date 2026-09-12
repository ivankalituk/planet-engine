#include "camera.hpp"

#include <glm/gtc/matrix_transform.hpp>

Camera::Camera()
    : position(0.0f, 2.0f, 3.0f),
    target(0.0f, 0.0f, 0.0f),
    up(0.0f, 1.0f, 0.0f)
{
}

glm::mat4 Camera::getViewMatrix() const
{
    return glm::lookAt(
        position,
        target,
        up
    );
}