#ifndef TEXTUREBUFFER_H
#define TEXTUREBUFFER_H

#include <string>
#include <sstream>
#include <iostream>

// include glm
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
// include glew
#include <GL/glew.h>
// include soil
#include <SOIL/SOIL.h>

/**
* @brief The Texture class
*/
class TextureBuffer
{
public:
	TextureBuffer(); ///< @brief Constructor of the TextureBuffer
	virtual ~TextureBuffer(); ///< @brief Destructor of the TextureBuffer

	/// @brief load a texture
	/// @param the location of the texture
	/// @param the filter type
	/// @param the wrap type
	/// @return void
	void loadTexture(const char* location, int filter, int wrap);
	/// @brief get the texture
	/// @return GLuint
	GLuint getTexture() { return _texture; };

private:
	GLuint _texture; ///< @brief the loaded texture
	 
	int _filter; ///< @brief the filter type
	int _wrap; ///< @brief the wrap type
};

#endif /* end TEXTUREBUFFER_H */