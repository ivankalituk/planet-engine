#include "camera.hpp"

#include <glm/gtc/matrix_transform.hpp>

Camera::Camera()
    : position(0.0f, 0.0f, 3.0f),
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

void Camera::move(const glm::vec3& offset)
{
    position += offset;
}

glm::vec3 Camera::getPosition() const
{
    return position;
}

glm::vec3 Camera::getRight() const
{
    glm::vec3 forward =
        glm::normalize(target - position);

    return glm::normalize(
        glm::cross(forward, up)
    );
}