#pragma once

#include <glm/glm.hpp>

class Camera
{
public:
    Camera();

    glm::mat4 getViewMatrix() const;

    void move(const glm::vec3& offset);
    void rotate(float angle, const glm::vec3& axis);
    void zoom(float amount);

    glm::vec3 getPosition() const;
    glm::vec3 getRight() const;

private:
    glm::vec3 position;
    glm::vec3 target;

    glm::vec3 forward;
    glm::vec3 right;
    glm::vec3 up;
};