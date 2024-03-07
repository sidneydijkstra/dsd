#include "renderable.h"

Renderable::Renderable() {
    transform = {
        glm::vec3(0.0f, 0.0f, 0.0f),
        glm::vec3(1.0f, 1.0f, 1.0f),
        glm::vec3(1.0f, 1.0f, 1.0f)
    };
    color = glm::vec3(1.0f, 1.0f, 1.0f);
    material = {
        glm::vec3(1.0f, 1.0f, 1.0f),
        glm::vec3(1.0f, 1.0f, 1.0f),
        glm::vec3(1.0f, 1.0f, 1.0f),
        32.0f
    };

    mesh = new Mesh();
    mesh->loadCube();
}

Renderable::~Renderable() {
    delete mesh;
    mesh = nullptr;
}
