
#ifndef RENDERER_H
#define RENDERER_H

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <iostream>

#include "shader.h"
#include "resourcemanager.h"
#include "camera.h"
#include "mesh.h"
#include "Renderable.h"
#include "light.h"

class Renderer {
public:
    Renderer();
    void render(Renderable* renderable, Shader* shader, Camera* camera, Light* light);
    void renderLight(Light* light, Shader* shader, Camera* camera);
private:
};

#endif