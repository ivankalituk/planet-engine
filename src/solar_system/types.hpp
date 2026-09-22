struct CelestialBody
{
    std::string id;
    std::string parentId;

    std::string name;

    float radius;

    float distanceFromParent;

    float orbitSpeed;
    float selfRotationSpeed;

    glm::vec3 orbitAxis;
};