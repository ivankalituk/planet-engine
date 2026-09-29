#include "state.hpp"

#include "../data/data.hpp"
#include <iostream>


std::vector<CelestialBodyState> celestialBodyStates;


const CelestialBody* getCelestialBody(const std::string& id) {
    for (const CelestialBody& body : celestialBodies) {
        if (body.id == id) {
            return &body;
        }
    }

    return nullptr;
}

void createCelestialBodyStates() {
    for (const CelestialBody& body : celestialBodies) {
        //std::cout << body.id << '\n';

        if (body.id == "STAR") {
            celestialBodyStates.push_back({
                body.id,
                body.parentId,
                {0.0f, 0.0f, 0.0f},
                {0.0f, 1.0f, 0.0f},
                body.selfRotationSpeed
            });
        }

        
        if (body.parentId == "STAR") {
            celestialBodyStates.push_back({
                body.id,
                body.parentId,
                {body.distanceFromParent , 0.0f, 0.0f},
                {0.0f, 1.0f, 0.0f}
            });
        }
        
        if (body.parentId != "STAR" && body.id != "STAR") {

            const CelestialBody* parentBody = getCelestialBody(body.parentId);

            celestialBodyStates.push_back({
                body.id,
                body.parentId,
                {body.distanceFromParent + parentBody->distanceFromParent , 0.0f, 0.0f},
                {0.0f, 1.0f, 0.0f}
            });
            
        }
    }
}

CelestialBodyState* getBodyState(const std::string& id) {
    for (CelestialBodyState& state : celestialBodyStates)
    {
        if (state.id == id)
        {
            return &state;
        }
    }

    return nullptr;
}

void updateCelestialBodies(float deltaTime) {
    for (std::size_t i = 0; i < celestialBodyStates.size(); i++)
    {
        celestialBodyStates[i].rotationAngle +=
            celestialBodies[i].selfRotationSpeed * deltaTime;
    }
}