
#ifndef RENDERABLE_H
#define RENDERABLE_H

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include "Transform.h"
#include "mesh.h"
#include "material.h"

class Renderable{
public:
	Renderable(); ///< @brief Constructor of the Renderable
	~Renderable(); ///< @brief Destructor of the Renderable

	Transform transform;
	glm::vec3 color;
	Material material;
	const char* texture;
	Mesh* mesh;
private:
};

#endif