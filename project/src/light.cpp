#include "light.h"

Light::Light() {
    transform = {
        glm::vec3(0.0f, 0.0f, 0.0f),
        glm::vec3(1.0f, 1.0f, 1.0f),
        glm::vec3(1.0f, 1.0f, 1.0f)
    };
    color = glm::vec3(1.0f, 1.0f, 1.0f);
    ambient = glm::vec3(1.0f, 1.0f, 1.0f);
    diffuse = glm::vec3(1.0f, 1.0f, 1.0f);
    specular = glm::vec3(1.0f, 1.0f, 1.0f);
}

Light::~Light()
{
}
