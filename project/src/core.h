
#ifndef CORE_H
#define CORE_H

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <iostream>

#include "config.h"
#include "input.h"
#include "renderer.h"
#include "shader.h"
#include "mesh.h"
#include "camera.h"
#include "renderer.h"

// https://github.com/vinceniko/3D-Scene-Renderer
class Core {
public:
    Core();
    ~Core();
    bool run(std::vector<Renderable*> children, std::vector<Light*> lights);
	Renderer* renderer;
private:
	GLFWwindow* _window;
	Input* input;
	Camera* camera;
	Shader* normalShader;
	Shader* lightShader;

	// Create a GLFW window
	void createWindow();

	// Calculate delta time of current frame
	void calculateDeltaTime();
	GLfloat deltaTime = 0.0f;
	GLfloat lastFrame = 0.0f;

	// Calculate fps of current frame
	void calculateFPS();
	GLfloat currentTime;
	GLfloat lastTime;
	GLfloat fps;
};

#endif