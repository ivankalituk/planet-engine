#include "data.hpp"

const std::vector<CelestialBody> celestialBodies = {
    {
        .id = "STAR",
        .parentId = "",
        .name = "Sun",
        .radius = 1.0f,
        .distanceFromParent = 0.0f,
        .orbitSpeed = 0.0f,
        .selfRotationSpeed = 20.0f,
        .orbitAxis = {0.0f, 1.0f, 0.0f}
    },

    {
        .id = "MERCURY",
        .parentId = "STAR",
        .name = "Mercury",
        .radius = 0.12f,
        .distanceFromParent = 2.0f,
        .orbitSpeed = 35.0f,
        .selfRotationSpeed = 12.0f,
        .orbitAxis = {0.0f, 1.0f, 0.0f}
    },

    {
        .id = "VENUS",
        .parentId = "STAR",
        .name = "Venus",
        .radius = 0.22f,
        .distanceFromParent = 3.0f,
        .orbitSpeed = 28.0f,
        .selfRotationSpeed = -8.0f,
        .orbitAxis = {0.0f, 1.0f, 0.0f}
    },

    {
        .id = "EARTH",
        .parentId = "STAR",
        .name = "Earth",
        .radius = 0.23f,
        .distanceFromParent = 4.2f,
        .orbitSpeed = 22.0f,
        .selfRotationSpeed = 30.0f,
        .orbitAxis = {0.0f, 1.0f, 0.0f}
    },

    {
        .id = "MOON",
        .parentId = "EARTH",
        .name = "Moon",
        .radius = 0.06f,
        .distanceFromParent = 0.45f,
        .orbitSpeed = 70.0f,
        .selfRotationSpeed = 70.0f,
        .orbitAxis = {0.0f, 1.0f, 0.0f}
    },

    {
        .id = "MARS",
        .parentId = "STAR",
        .name = "Mars",
        .radius = 0.17f,
        .distanceFromParent = 5.8f,
        .orbitSpeed = 16.0f,
        .selfRotationSpeed = 28.0f,
        .orbitAxis = {0.0f, 1.0f, 0.0f}
    },

    {
        .id = "PHOBOS",
        .parentId = "MARS",
        .name = "Phobos",
        .radius = 0.03f,
        .distanceFromParent = 0.30f,
        .orbitSpeed = 120.0f,
        .selfRotationSpeed = 45.0f,
        .orbitAxis = {0.0f, 1.0f, 0.0f}
    },

    {
        .id = "DEIMOS",
        .parentId = "MARS",
        .name = "Deimos",
        .radius = 0.02f,
        .distanceFromParent = 0.55f,
        .orbitSpeed = 80.0f,
        .selfRotationSpeed = 35.0f,
        .orbitAxis = {0.0f, 1.0f, 0.0f}
    }
};