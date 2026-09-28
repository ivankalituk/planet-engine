#include "sphere.hpp"

#include <cmath>

namespace
{
    constexpr float PI = 3.14159265358979323846f;

    void addVertex(
        SphereInfo& sphere,
        const Position& position,
        float colorIndex
    )
    {
        sphere.vertices.push_back(position.x);
        sphere.vertices.push_back(position.y);
        sphere.vertices.push_back(position.z);

        sphere.vertices.push_back(colorIndex);
    }

    void createQuad(
        SphereInfo& sphere,
        const Position& topLeft,
        const Position& topRight,
        const Position& bottomLeft,
        const Position& bottomRight,
        bool darkColor
    )
    {
        const float colorIndex =
            darkColor ? 1.0f : 0.0f;

        // Первый треугольник
        addVertex(sphere, topLeft, colorIndex);
        addVertex(sphere, bottomLeft, colorIndex);
        addVertex(sphere, topRight, colorIndex);

        // Второй треугольник
        addVertex(sphere, topRight, colorIndex);
        addVertex(sphere, bottomLeft, colorIndex);
        addVertex(sphere, bottomRight, colorIndex);
    }

    void createPoleTriangle(
        SphereInfo& sphere,
        const Position& pole,
        const Position& left,
        const Position& right,
        bool darkColor
    )
    {
        const float colorIndex =
            darkColor ? 1.0f : 0.0f;

        addVertex(sphere, pole, colorIndex);
        addVertex(sphere, left, colorIndex);
        addVertex(sphere, right, colorIndex);
    }

    Position getSpherePoint(
        const SphereSettings& settings,
        float latitudeAngle,
        float longitudeAngle
    )
    {
        const float cosLat =
            std::cos(latitudeAngle);

        return {
            settings.position.x +
                settings.radius *
                cosLat *
                std::cos(longitudeAngle),

            settings.position.y +
                settings.radius *
                std::sin(latitudeAngle),

            settings.position.z +
                settings.radius *
                cosLat *
                std::sin(longitudeAngle)
        };
    }
}

SphereInfo getSphereInfo(const SphereSettings& settings)
{
    SphereInfo sphere;

    const float latitudeStep =
        PI /
        static_cast<float>(settings.latitudeCount);

    const float longitudeStep =
        2.0f * PI /
        static_cast<float>(settings.meridianCount);

    const Position northPole = {
        settings.position.x,
        settings.position.y + settings.radius,
        settings.position.z
    };

    const Position southPole = {
        settings.position.x,
        settings.position.y - settings.radius,
        settings.position.z
    };

    // -------------------------
    // Северный полюс
    // -------------------------

    {
        const float latitude =
            PI / 2.0f - latitudeStep;

        for (
            int meridian = 0;
            meridian < settings.meridianCount;
            meridian++
            )
        {
            const float currentLongitude =
                meridian * longitudeStep;

            const float nextLongitude =
                (meridian + 1) * longitudeStep;

            Position left =
                getSpherePoint(
                    settings,
                    latitude,
                    currentLongitude
                );

            Position right =
                getSpherePoint(
                    settings,
                    latitude,
                    nextLongitude
                );

            createPoleTriangle(
                sphere,
                northPole,
                left,
                right,
                (meridian % 2) == 0
            );
        }
    }

    // -------------------------
    // Все широты между полюсами
    // -------------------------

    for (
        int latitudeIndex = 1;
        latitudeIndex < settings.latitudeCount - 1;
        latitudeIndex++
        )
    {
        const float currentLatitude =
            PI / 2.0f -
            latitudeIndex * latitudeStep;

        const float nextLatitude =
            PI / 2.0f -
            (latitudeIndex + 1) * latitudeStep;

        for (
            int meridian = 0;
            meridian < settings.meridianCount;
            meridian++
            )
        {
            const float currentLongitude =
                meridian * longitudeStep;

            const float nextLongitude =
                (meridian + 1) * longitudeStep;

            Position topLeft =
                getSpherePoint(
                    settings,
                    currentLatitude,
                    currentLongitude
                );

            Position topRight =
                getSpherePoint(
                    settings,
                    currentLatitude,
                    nextLongitude
                );

            Position bottomLeft =
                getSpherePoint(
                    settings,
                    nextLatitude,
                    currentLongitude
                );

            Position bottomRight =
                getSpherePoint(
                    settings,
                    nextLatitude,
                    nextLongitude
                );

            createQuad(
                sphere,
                topLeft,
                topRight,
                bottomLeft,
                bottomRight,
                ((latitudeIndex + meridian) % 2) == 0
            );
        }
    }

    // -------------------------
    // Южный полюс
    // -------------------------

    {
        const float latitude =
            -PI / 2.0f + latitudeStep;

        for (
            int meridian = 0;
            meridian < settings.meridianCount;
            meridian++
            )
        {
            const float currentLongitude =
                meridian * longitudeStep;

            const float nextLongitude =
                (meridian + 1) * longitudeStep;

            Position left =
                getSpherePoint(
                    settings,
                    latitude,
                    currentLongitude
                );

            Position right =
                getSpherePoint(
                    settings,
                    latitude,
                    nextLongitude
                );

            createPoleTriangle(
                sphere,
                southPole,
                right,
                left,
                (meridian % 2) == 0
            );
        }
    }

    sphere.vertexCount =
        static_cast<int>(
            sphere.vertices.size() / 4
            );

    return sphere;
}