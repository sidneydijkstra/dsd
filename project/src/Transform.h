
#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <glm/glm.hpp>

struct Transform {
	glm::vec3 position = glm::vec3(0, 0, 0);
	glm::vec3 rotation = glm::vec3(1, 1, 1);
	glm::vec3 scale = glm::vec3(1, 1, 1);
};

#endif