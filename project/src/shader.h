#ifndef SHADER_H
#define SHADER_H

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <gtc/type_ptr.hpp>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader
{
public:
	/// @brief Constructor of the Shader
	/// @param the vertex Shader location
	/// @param the fragment Shader location
	Shader(const GLchar* vertexPath, const GLchar* fragmentPath);

	/// @brief use the current Shader program
	/// @return void
	void Use();

	/// @brief set a glm::mat4 in the 
	/// @param the name of the variable in the Shader
	/// @param the value you want to set it to
	/// @return void
	void setMat4(const char* name, glm::mat4 value);
	/// @brief set a glm::vec3 in the 
	/// @param the name of the variable in the Shader
	/// @param the value you want to set it to
	/// @return void
	void setVec3(const char* name, glm::vec3 value);
	/// @brief set a float in the 
	/// @param the name of the variable in the Shader
	/// @param the value you want to set it to
	/// @return void
	void setFloat(const char* name, float value);
	/// @brief set a int in the 
	/// @param the name of the variable in the Shader
	/// @param the value you want to set it to
	/// @return void
	void setInt(const char * name, float value);
	/// @brief set a bool in the 
	/// @param the name of the variable in the Shader
	/// @param the value you want to set it to
	/// @return void
	void setBool(const char * name, bool value);
	
	// The program ID
	GLuint program;
private:
};

#endif