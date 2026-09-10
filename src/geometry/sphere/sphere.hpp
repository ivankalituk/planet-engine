#pragma once

#include <vector>

struct Position {
	float x;
	float y;
	float z;
};

struct SphereInfo {
	std::vector<float> vertices;
	int vertexCount;
};

struct SphereSettings {
	Position position;
	float radius;
	int latitudeCount;
	int meridianCount;
};

SphereInfo getSphereInfo(const SphereSettings& settings);