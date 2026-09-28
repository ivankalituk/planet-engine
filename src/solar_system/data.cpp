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
        .orbitAxis = {0.0f, 1.0f, 0.0f},
        .rotationAxis = {0.126f, 0.992f, 0.0f},
        .primaryColor = {1.0f, 0.75f, 0.15f},
        .secondaryColor = {0.95f, 0.45f, 0.05f}
    },

    {
        .id = "MERCURY",
        .parentId = "STAR",
        .name = "Mercury",
        .radius = 0.12f,
        .distanceFromParent = 2.0f,
        .orbitSpeed = 35.0f,
        .selfRotationSpeed = 12.0f,
        .orbitAxis = {0.0f, 1.0f, 0.0f},
        .rotationAxis = {0.001f, 1.0f, 0.0f},
        .primaryColor = {0.55f, 0.55f, 0.52f},
        .secondaryColor = {0.32f, 0.32f, 0.30f}
    },

    {
        .id = "VENUS",
        .parentId = "STAR",
        .name = "Venus",
        .radius = 0.22f,
        .distanceFromParent = 3.0f,
        .orbitSpeed = 28.0f,
        .selfRotationSpeed = -8.0f,
        .orbitAxis = {0.0f, 1.0f, 0.0f},
        .rotationAxis = {0.045f, -0.999f, 0.0f},
        .primaryColor = {0.90f, 0.72f, 0.42f},
        .secondaryColor = {0.62f, 0.45f, 0.24f}
    },

    {
        .id = "EARTH",
        .parentId = "STAR",
        .name = "Earth",
        .radius = 0.23f,
        .distanceFromParent = 4.2f,
        .orbitSpeed = 22.0f,
        .selfRotationSpeed = 30.0f,
        .orbitAxis = {0.0f, 1.0f, 0.0f},
        .rotationAxis = {0.398f, 0.917f, 0.0f},
        .primaryColor = {0.08f, 0.30f, 0.72f},
        .secondaryColor = {0.16f, 0.55f, 0.18f}
    },

    {
        .id = "MOON",
        .parentId = "EARTH",
        .name = "Moon",
        .radius = 0.06f,
        .distanceFromParent = 0.45f,
        .orbitSpeed = 70.0f,
        .selfRotationSpeed = 70.0f,
        .orbitAxis = {0.0f, 1.0f, 0.0f},
        .rotationAxis = {0.116f, 0.993f, 0.0f},
        .primaryColor = {0.70f, 0.70f, 0.68f},
        .secondaryColor = {0.38f, 0.38f, 0.36f}
    },

    {
        .id = "MARS",
        .parentId = "STAR",
        .name = "Mars",
        .radius = 0.17f,
        .distanceFromParent = 5.8f,
        .orbitSpeed = 16.0f,
        .selfRotationSpeed = 28.0f,
        .orbitAxis = {0.0f, 1.0f, 0.0f},
        .rotationAxis = {0.425f, 0.906f, 0.0f},
        .primaryColor = {0.72f, 0.28f, 0.16f},
        .secondaryColor = {0.42f, 0.12f, 0.08f}
    },

    {
        .id = "PHOBOS",
        .parentId = "MARS",
        .name = "Phobos",
        .radius = 0.03f,
        .distanceFromParent = 0.30f,
        .orbitSpeed = 120.0f,
        .selfRotationSpeed = 45.0f,
        .orbitAxis = {0.0f, 1.0f, 0.0f},
        .rotationAxis = {0.0f, 1.0f, 0.0f},
        .primaryColor = {0.45f, 0.40f, 0.34f},
        .secondaryColor = {0.25f, 0.23f, 0.20f}
    },

    {
        .id = "DEIMOS",
        .parentId = "MARS",
        .name = "Deimos",
        .radius = 0.02f,
        .distanceFromParent = 0.55f,
        .orbitSpeed = 80.0f,
        .selfRotationSpeed = 35.0f,
        .orbitAxis = {0.0f, 1.0f, 0.0f},
        .rotationAxis = {0.0f, 1.0f, 0.0f},
        .primaryColor = {0.50f, 0.45f, 0.39f},
        .secondaryColor = {0.28f, 0.26f, 0.23f}
    }
};