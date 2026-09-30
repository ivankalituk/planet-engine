#include "data.hpp"
#include "../types.hpp"

const std::vector<CelestialBody> celestialBodies = {
    {
        .id = "STAR",
        .parentId = "",
        .name = "Sun",
        .radius = 3.0f,
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
        .distanceFromParent = 3.8f,
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
        .distanceFromParent = 5.0f,
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
        .distanceFromParent = 6.5f,
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
        .distanceFromParent = 8.5f,
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
    },

    {
        .id = "JUPITER",
        .parentId = "STAR",
        .name = "Jupiter",
        .radius = 0.70f,
        .distanceFromParent = 11.5f,
        .orbitSpeed = 11.0f,
        .selfRotationSpeed = 45.0f,
        .orbitAxis = {0.0f, 1.0f, 0.0f},
        .rotationAxis = {0.0f, 0.999f, 0.052f},
        .primaryColor = {0.72f, 0.55f, 0.38f},
        .secondaryColor = {0.42f, 0.28f, 0.18f}
    },

    {
        .id = "IO",
        .parentId = "JUPITER",
        .name = "Io",
        .radius = 0.11f,
        .distanceFromParent = 0.95f,
        .orbitSpeed = 90.0f,
        .selfRotationSpeed = 90.0f,
        .orbitAxis = {0.0f, 1.0f, 0.0f},
        .rotationAxis = {0.0f, 1.0f, 0.0f},
        .primaryColor = {0.90f, 0.72f, 0.25f},
        .secondaryColor = {0.55f, 0.32f, 0.12f}
    },

    {
        .id = "EUROPA",
        .parentId = "JUPITER",
        .name = "Europa",
        .radius = 0.10f,
        .distanceFromParent = 1.20f,
        .orbitSpeed = 65.0f,
        .selfRotationSpeed = 65.0f,
        .orbitAxis = {0.0f, 1.0f, 0.0f},
        .rotationAxis = {0.0f, 1.0f, 0.0f},
        .primaryColor = {0.78f, 0.74f, 0.62f},
        .secondaryColor = {0.48f, 0.42f, 0.32f}
    },

    {
        .id = "GANYMEDE",
        .parentId = "JUPITER",
        .name = "Ganymede",
        .radius = 0.13f,
        .distanceFromParent = 1.50f,
        .orbitSpeed = 45.0f,
        .selfRotationSpeed = 45.0f,
        .orbitAxis = {0.0f, 1.0f, 0.0f},
        .rotationAxis = {0.0f, 1.0f, 0.0f},
        .primaryColor = {0.52f, 0.50f, 0.45f},
        .secondaryColor = {0.30f, 0.28f, 0.25f}
    },

    {
        .id = "CALLISTO",
        .parentId = "JUPITER",
        .name = "Callisto",
        .radius = 0.12f,
        .distanceFromParent = 1.85f,
        .orbitSpeed = 30.0f,
        .selfRotationSpeed = 30.0f,
        .orbitAxis = {0.0f, 1.0f, 0.0f},
        .rotationAxis = {0.0f, 1.0f, 0.0f},
        .primaryColor = {0.45f, 0.43f, 0.38f},
        .secondaryColor = {0.25f, 0.23f, 0.20f}
    },

    {
        .id = "SATURN",
        .parentId = "STAR",
        .name = "Saturn",
        .radius = 0.60f,
        .distanceFromParent = 15.0f,
        .orbitSpeed = 8.0f,
        .selfRotationSpeed = 43.0f,
        .orbitAxis = {0.0f, 1.0f, 0.0f},
        .rotationAxis = {0.0f, 0.999f, 0.045f},
        .primaryColor = {0.78f, 0.68f, 0.48f},
        .secondaryColor = {0.50f, 0.40f, 0.25f}
    },

    {
        .id = "TITAN",
        .parentId = "SATURN",
        .name = "Titan",
        .radius = 0.13f,
        .distanceFromParent = 0.95f,
        .orbitSpeed = 50.0f,
        .selfRotationSpeed = 50.0f,
        .orbitAxis = {0.0f, 1.0f, 0.0f},
        .rotationAxis = {0.0f, 1.0f, 0.0f},
        .primaryColor = {0.72f, 0.48f, 0.22f},
        .secondaryColor = {0.45f, 0.28f, 0.12f}
    },

    {
        .id = "RHEA",
        .parentId = "SATURN",
        .name = "Rhea",
        .radius = 0.09f,
        .distanceFromParent = 1.25f,
        .orbitSpeed = 38.0f,
        .selfRotationSpeed = 38.0f,
        .orbitAxis = {0.0f, 1.0f, 0.0f},
        .rotationAxis = {0.0f, 1.0f, 0.0f},
        .primaryColor = {0.65f, 0.63f, 0.58f},
        .secondaryColor = {0.38f, 0.36f, 0.32f}
    },

    {
        .id = "IAPETUS",
        .parentId = "SATURN",
        .name = "Iapetus",
        .radius = 0.08f,
        .distanceFromParent = 1.55f,
        .orbitSpeed = 28.0f,
        .selfRotationSpeed = 28.0f,
        .orbitAxis = {0.0f, 1.0f, 0.0f},
        .rotationAxis = {0.0f, 1.0f, 0.0f},
        .primaryColor = {0.55f, 0.52f, 0.46f},
        .secondaryColor = {0.25f, 0.23f, 0.20f}
    },

    {
        .id = "DIONE",
        .parentId = "SATURN",
        .name = "Dione",
        .radius = 0.07f,
        .distanceFromParent = 1.80f,
        .orbitSpeed = 25.0f,
        .selfRotationSpeed = 25.0f,
        .orbitAxis = {0.0f, 1.0f, 0.0f},
        .rotationAxis = {0.0f, 1.0f, 0.0f},
        .primaryColor = {0.68f, 0.67f, 0.63f},
        .secondaryColor = {0.40f, 0.39f, 0.36f}
    },

    {
        .id = "TETHYS",
        .parentId = "SATURN",
        .name = "Tethys",
        .radius = 0.07f,
        .distanceFromParent = 2.05f,
        .orbitSpeed = 22.0f,
        .selfRotationSpeed = 22.0f,
        .orbitAxis = {0.0f, 1.0f, 0.0f},
        .rotationAxis = {0.0f, 1.0f, 0.0f},
        .primaryColor = {0.72f, 0.70f, 0.66f},
        .secondaryColor = {0.42f, 0.40f, 0.36f}
    },

    {
        .id = "ENCELADUS",
        .parentId = "SATURN",
        .name = "Enceladus",
        .radius = 0.055f,
        .distanceFromParent = 2.25f,
        .orbitSpeed = 20.0f,
        .selfRotationSpeed = 20.0f,
        .orbitAxis = {0.0f, 1.0f, 0.0f},
        .rotationAxis = {0.0f, 1.0f, 0.0f},
        .primaryColor = {0.88f, 0.89f, 0.86f},
        .secondaryColor = {0.55f, 0.58f, 0.56f}
    },

    {
        .id = "URANUS",
        .parentId = "STAR",
        .name = "Uranus",
        .radius = 0.46f,
        .distanceFromParent = 18.5f,
        .orbitSpeed = 6.0f,
        .selfRotationSpeed = -38.0f,
        .orbitAxis = {0.0f, 1.0f, 0.0f},
        .rotationAxis = {0.0f, -0.42f, 0.91f},
        .primaryColor = {0.45f, 0.78f, 0.82f},
        .secondaryColor = {0.25f, 0.55f, 0.62f}
    },

    {
        .id = "TITANIA",
        .parentId = "URANUS",
        .name = "Titania",
        .radius = 0.08f,
        .distanceFromParent = 0.75f,
        .orbitSpeed = 35.0f,
        .selfRotationSpeed = 35.0f,
        .orbitAxis = {0.0f, 1.0f, 0.0f},
        .rotationAxis = {0.0f, 1.0f, 0.0f},
        .primaryColor = {0.58f, 0.57f, 0.52f},
        .secondaryColor = {0.34f, 0.33f, 0.30f}
    },

    {
        .id = "OBERON",
        .parentId = "URANUS",
        .name = "Oberon",
        .radius = 0.08f,
        .distanceFromParent = 1.05f,
        .orbitSpeed = 27.0f,
        .selfRotationSpeed = 27.0f,
        .orbitAxis = {0.0f, 1.0f, 0.0f},
        .rotationAxis = {0.0f, 1.0f, 0.0f},
        .primaryColor = {0.48f, 0.46f, 0.42f},
        .secondaryColor = {0.27f, 0.25f, 0.22f}
    },

    {
        .id = "UMBRIEL",
        .parentId = "URANUS",
        .name = "Umbriel",
        .radius = 0.06f,
        .distanceFromParent = 1.30f,
        .orbitSpeed = 23.0f,
        .selfRotationSpeed = 23.0f,
        .orbitAxis = {0.0f, 1.0f, 0.0f},
        .rotationAxis = {0.0f, 1.0f, 0.0f},
        .primaryColor = {0.38f, 0.37f, 0.35f},
        .secondaryColor = {0.21f, 0.20f, 0.19f}
    },

    {
        .id = "NEPTUNE",
        .parentId = "STAR",
        .name = "Neptune",
        .radius = 0.44f,
        .distanceFromParent = 22.0f,
        .orbitSpeed = 5.0f,
        .selfRotationSpeed = 42.0f,
        .orbitAxis = {0.0f, 1.0f, 0.0f},
        .rotationAxis = {0.0f, 0.999f, -0.045f},
        .primaryColor = {0.12f, 0.32f, 0.78f},
        .secondaryColor = {0.06f, 0.16f, 0.48f}
    },

    {
        .id = "TRITON",
        .parentId = "NEPTUNE",
        .name = "Triton",
        .radius = 0.09f,
        .distanceFromParent = 0.80f,
        .orbitSpeed = -32.0f,
        .selfRotationSpeed = 32.0f,
        .orbitAxis = {0.0f, 1.0f, 0.0f},
        .rotationAxis = {0.0f, 1.0f, 0.0f},
        .primaryColor = {0.68f, 0.72f, 0.76f},
        .secondaryColor = {0.40f, 0.45f, 0.50f}
    }
};