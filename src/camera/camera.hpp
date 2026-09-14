#pragma once

#include <glm/glm.hpp>

class Camera
{
public:
    Camera();

    glm::mat4 getViewMatrix() const;

    void move(const glm::vec3& offset);

private:
    glm::vec3 position;
    glm::vec3 target;
    glm::vec3 up;
};