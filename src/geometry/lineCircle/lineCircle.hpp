#pragma once

#include <vector>
#include <glm/glm.hpp>

struct LineCircleInfo {
	std::vector<float> vertices;
	int vertexCount;
};

struct LineCircleSettings {
    glm::vec3 position;
    float radius;
    int linesCount;
};

LineCircleInfo getLineCircleInfp(const LineCircleSettings& settings);