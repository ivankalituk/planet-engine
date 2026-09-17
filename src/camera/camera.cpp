#include "camera.hpp"

#include <glm/gtc/matrix_transform.hpp>

Camera::Camera()
    : position(0.0f, 0.0f, 3.0f),
    target(0.0f, 0.0f, 0.0f),
    forward(0.0f, 0.0f, -1.0f),
    right(1.0f, 0.0f, 0.0f),
    up(0.0f, 1.0f, 0.0f)
{
}

glm::mat4 Camera::getViewMatrix() const
{
    return glm::lookAt(
        position,
        position + forward,
        up
    );
}

void Camera::move(const glm::vec3& offset)
{
    position += offset;
}

void Camera::rotate(float angle, const glm::vec3& axis)
{
    glm::mat4 rotation =
        glm::rotate(
            glm::mat4(1.0f),
            angle,
            axis
        );

    position =
        glm::vec3(
            rotation * glm::vec4(position, 1.0f)
        );

    forward =
        glm::normalize(
            glm::vec3(
                rotation * glm::vec4(forward, 0.0f)
            )
        );

    up =
        glm::normalize(
            glm::vec3(
                rotation * glm::vec4(up, 0.0f)
            )
        );

    right =
        glm::normalize(
            glm::vec3(
                rotation * glm::vec4(right, 0.0f)
            )
        );
}

glm::vec3 Camera::getPosition() const
{
    return position;
}

glm::vec3 Camera::getRight() const
{
    return right;
}