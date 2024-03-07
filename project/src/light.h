
#ifndef LIGHT_H
#define LIGHT_H

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

class Light {
public:
	Light();
	~Light();

	Transform transform;
	glm::vec3 color;
    glm::vec3 ambient;
    glm::vec3 diffuse;
    glm::vec3 specular;

	Mesh* mesh;
private:
};

#endif