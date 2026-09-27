#include "state.hpp"

#include "../data.hpp"

std::vector<CelestialBodyState> celestialBodyStates;

void createCelestialBodyStates()
{
    for (const CelestialBody& body : celestialBodies)
    {
        celestialBodyStates.push_back({
            body.id,
            {0.0f, 0.0f, 0.0f},
            {0.0f, 1.0f, 0.0f}
        });
    }
}

CelestialBodyState* getBodyState(const std::string& id)
{
    for (CelestialBodyState& state : celestialBodyStates)
    {
        if (state.id == id)
        {
            return &state;
        }
    }

    return nullptr;
}