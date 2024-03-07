
#ifndef MESH_H
#define MESH_H

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Mesh{
public:
	Mesh(); ///< @brief Constructor of the Mesh
	~Mesh(); ///< @brief Destructor of the Mesh
	
	// mesh transform variables
	glm::vec3 position = glm::vec3(0, 0, 0);
	glm::vec3 rotation = glm::vec3(1, 1, 1);
	glm::vec3 scale = glm::vec3(1, 1, 1);

	// mesh buffer varables
	GLuint VAO; ///< @brief the VAO buffer of Mesh
	GLuint VBO; ///< @brief the VBO buffer of Mesh
	int drawsize; ///< @brief the drawsize of Mesh

	/// @brief load the Mesh for a cube
	/// @return void
	void loadCube();
	/// @brief load the Mesh for a quad
	/// @return void
	void loadQuad();
	/// @brief load the Mesh for a object with a .obj file
	/// @param the file location
	/// @return void
	void loadObject(const char * location);
private:
};

#endif