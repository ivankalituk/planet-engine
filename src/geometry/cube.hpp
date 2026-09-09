#pragma once

#include <vector>

struct Position {
    float x;
    float y;
    float z;
};

struct FigureInfo {
    std::vector<float> vertices;
    int vertexCount;
};

struct CubeSettings {
    Position position;
    float edgeLength;
};

FigureInfo getFigureInfo(const CubeSettings& settings);