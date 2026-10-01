#include "lineCircle.hpp"
#include <glm/gtc/matrix_transform.hpp>

namespace {
    constexpr float PI = 3.14159265358979323846f;
}

LineCircleInfo getLineCircleInfo(const LineCircleSettings& settings) {

    const glm::vec3 rotateAxis = glm::vec3(0.0f, 1.0f, 0.0f);

    const float rotationAngle = 2 * PI / settings.linesCount;

    glm::vec3 initialPosition =
        settings.position +
        glm::vec3(settings.radius, 0.0f, 0.0f);

    LineCircleInfo lineCircleInfo;
    lineCircleInfo.vertices.reserve(settings.linesCount * 3);
    lineCircleInfo.vertices.push_back(initialPosition.x);
    lineCircleInfo.vertices.push_back(initialPosition.y);
    lineCircleInfo.vertices.push_back(initialPosition.z);

    for (int i = 1; i < settings.linesCount; i++) {

        glm::vec3 relativePosition =
            initialPosition - settings.position;

        glm::mat4 rotationMatrix = glm::rotate(
            glm::mat4(1.0f),
            rotationAngle,
            rotateAxis
        );

        glm::vec4 newRelativePosition =
            rotationMatrix *
            glm::vec4(relativePosition, 0.0f);

        initialPosition =
            settings.position +
            glm::vec3(newRelativePosition);

        lineCircleInfo.vertices.push_back(initialPosition.x);
        lineCircleInfo.vertices.push_back(initialPosition.y);
        lineCircleInfo.vertices.push_back(initialPosition.z);
    }

    lineCircleInfo.vertexCount =
        static_cast<int>(lineCircleInfo.vertices.size() / 3);

    return lineCircleInfo;
}