#include "data.hpp"

const std::vector<Planet> planets = {
    {
        .id = "STAR",
        .parentId = "",
        .name = "Sun",
        .radius = 1.0f,
        .distanceFromParent = 0.0f,
        .orbitSpeed = 0.0f,
        .selfRotationSpeed = 0.08f,
        .orbitAxis = {0.0f, 1.0f, 0.0f}
    },

    {
        .id = "MERCURY",
        .parentId = "STAR",
        .name = "Mercury",
        .radius = 0.12f,
        .distanceFromParent = 2.0f,
        .orbitSpeed = 1.60f,
        .selfRotationSpeed = 0.02f,
        .orbitAxis = {0.0f, 1.0f, 0.0f}
    },

    {
        .id = "VENUS",
        .parentId = "STAR",
        .name = "Venus",
        .radius = 0.22f,
        .distanceFromParent = 3.0f,
        .orbitSpeed = 1.15f,
        .selfRotationSpeed = -0.01f,
        .orbitAxis = {0.0f, 1.0f, 0.0f}
    },

    {
        .id = "EARTH",
        .parentId = "STAR",
        .name = "Earth",
        .radius = 0.23f,
        .distanceFromParent = 4.2f,
        .orbitSpeed = 1.00f,
        .selfRotationSpeed = 1.00f,
        .orbitAxis = {0.0f, 1.0f, 0.0f}
    },

    {
        .id = "MOON",
        .parentId = "EARTH",
        .name = "Moon",
        .radius = 0.06f,
        .distanceFromParent = 0.45f,
        .orbitSpeed = 4.00f,
        .selfRotationSpeed = 0.20f,
        .orbitAxis = {0.0f, 1.0f, 0.0f}
    },

    {
        .id = "MARS",
        .parentId = "STAR",
        .name = "Mars",
        .radius = 0.17f,
        .distanceFromParent = 5.8f,
        .orbitSpeed = 0.80f,
        .selfRotationSpeed = 0.95f,
        .orbitAxis = {0.0f, 1.0f, 0.0f}
    },

    {
        .id = "PHOBOS",
        .parentId = "MARS",
        .name = "Phobos",
        .radius = 0.03f,
        .distanceFromParent = 0.30f,
        .orbitSpeed = 8.00f,
        .selfRotationSpeed = 0.30f,
        .orbitAxis = {0.0f, 1.0f, 0.0f}
    },

    {
        .id = "DEIMOS",
        .parentId = "MARS",
        .name = "Deimos",
        .radius = 0.02f,
        .distanceFromParent = 0.55f,
        .orbitSpeed = 5.50f,
        .selfRotationSpeed = 0.25f,
        .orbitAxis = {0.0f, 1.0f, 0.0f}
    }
};