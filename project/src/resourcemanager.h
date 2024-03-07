/**
* @file resourcemanager.h
*
* @brief The Resourcemanager header file.
*
* This file is part of SDENV2, a 2D/3D OpenGL framework.
*
*/

#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <string>
#include <sstream>
#include <iostream>
#include <map>

// include glm
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
// include glew
#include <GL/glew.h>

#include "texturebuffer.h"

/**
* @brief The ResourceManager class
*/
class ResourceManager
{
public:
	ResourceManager(); ///< @brief Constructor of the ResourceManager
	~ResourceManager(); ///< @brief Destructor of the ResourceManager
	
	/// @brief Static get instance function, ResourceManager is a singleton because we only need one instance.
	/// @return A pointer to ResourceManager.
	static ResourceManager* getInstance();
	/// @brief Static function to delete and cleanup the ResourceManager.
	static void deleteInstance();

	/// @brief get a texture
	/// @param the location of the texture
	/// @param the filter type
	/// @param the wrap type
	/// @return GLuint
	GLuint getTexture(const char* location, int filter, int wrap);

private:
	std::map<std::string, TextureBuffer*> _textureBuffers; ///< @brief the map of already loaded texture buffers
};

#endif /* end RESOURCEMANAGER_H */