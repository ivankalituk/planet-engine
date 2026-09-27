#pragma once

#include <string>
#include <vector>

#include <glm/vec3.hpp>

struct CelestialBodyState
{
    std::string id;

    glm::vec3 position;
    glm::vec3 rotationAxis;
    float rotationAngle;
};

extern std::vector<CelestialBodyState> celestialBodyStates;

void createCelestialBodyStates();

CelestialBodyState* getBodyState(const std::string& id);

void updateCelestialBodies(float deltaTime);