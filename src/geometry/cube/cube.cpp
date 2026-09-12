#include "cube.hpp"

FigureInfo getFigureInfo(const CubeSettings& settings)
{
    const float x = settings.position.x;
    const float y = settings.position.y;
    const float z = settings.position.z;

    const float half = settings.edgeLength / 2.0f;

    float red = 1.0f;

    std::vector<float> vertices = {

        // FRONT
        x - half, y - half, z + half, red, 0.0f, 0.0f,
        x + half, y - half, z + half, red, 0.0f, 0.0f,
        x + half, y + half, z + half, red, 0.0f, 0.0f,

        x + half, y + half, z + half, red, 0.0f, 0.0f,
        x - half, y + half, z + half, red, 0.0f, 0.0f,
        x - half, y - half, z + half, red, 0.0f, 0.0f,

        // BACK
        x - half, y - half, z - half, red *= 0.8f, 0.0f, 0.0f,
        x + half, y - half, z - half, red, 0.0f, 0.0f,
        x + half, y + half, z - half, red, 0.0f, 0.0f,

        x + half, y + half, z - half, red, 0.0f, 0.0f,
        x - half, y + half, z - half, red, 0.0f, 0.0f,
        x - half, y - half, z - half, red, 0.0f, 0.0f,

        // LEFT
        x - half, y - half, z - half, red *= 0.8f, 0.0f, 0.0f,
        x - half, y - half, z + half, red, 0.0f, 0.0f,
        x - half, y + half, z + half, red, 0.0f, 0.0f,

        x - half, y + half, z + half, red, 0.0f, 0.0f,
        x - half, y + half, z - half, red, 0.0f, 0.0f,
        x - half, y - half, z - half, red, 0.0f, 0.0f,

        // RIGHT
        x + half, y - half, z - half, red *= 0.8f, 0.0f, 0.0f,
        x + half, y - half, z + half, red, 0.0f, 0.0f,
        x + half, y + half, z + half, red, 0.0f, 0.0f,

        x + half, y + half, z + half, red, 0.0f, 0.0f,
        x + half, y + half, z - half, red, 0.0f, 0.0f,
        x + half, y - half, z - half, red, 0.0f, 0.0f,

        // TOP
        x - half, y + half, z + half, red *= 0.8f, 0.0f, 0.0f,
        x + half, y + half, z + half, red, 0.0f, 0.0f,
        x + half, y + half, z - half, red, 0.0f, 0.0f,

        x + half, y + half, z - half, red, 0.0f, 0.0f,
        x - half, y + half, z - half, red, 0.0f, 0.0f,
        x - half, y + half, z + half, red, 0.0f, 0.0f,

        // BOTTOM
        x - half, y - half, z - half, red *= 0.8f, 0.0f, 0.0f,
        x + half, y - half, z - half, red, 0.0f, 0.0f,
        x + half, y - half, z + half, red, 0.0f, 0.0f,

        x + half, y - half, z + half, red, 0.0f, 0.0f,
        x - half, y - half, z + half, red, 0.0f, 0.0f,
        x - half, y - half, z - half, red, 0.0f, 0.0f
    };

    return {
        vertices,
        36
    };
}