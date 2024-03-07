#include "resourcemanager.h"

static ResourceManager* _instance;

ResourceManager::ResourceManager(){
	_textureBuffers = std::map<std::string, TextureBuffer*>();
}

ResourceManager::~ResourceManager(){
	std::map<std::string, TextureBuffer*>::iterator text_it;
	for (text_it = _textureBuffers.begin(); text_it != _textureBuffers.end(); ++text_it) {
		if (text_it->second != NULL) {
			delete text_it->second;
		}
	}
	_textureBuffers.clear();
}

ResourceManager* ResourceManager::getInstance() {
	if (!_instance) {
		_instance = new ResourceManager();
	}
	return _instance;
}

void ResourceManager::deleteInstance() {
	delete _instance;
	_instance = nullptr;
}

GLuint ResourceManager::getTexture(const char * location, int filter, int wrap){
	if (_textureBuffers[location] != NULL) {
		return _textureBuffers[location]->getTexture();
	}

	TextureBuffer* t = new TextureBuffer();
	t->loadTexture(location, filter, wrap);

	_textureBuffers[location] = t;

	return _textureBuffers[location]->getTexture();
}
