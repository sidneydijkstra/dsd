
#include <iostream>
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include "core.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

int main() {
    Core* core = new Core();
    
    std::vector<Renderable*> children = {};
    std::vector<Light*> lights = {};

    for (size_t i = 0; i < 5; i++)
    {
        for (size_t j = 0; j < 5; j++)
        {
            Renderable* renderable = new Renderable();
            renderable->transform.position = glm::vec3(0, 5, 0);
            renderable->transform.position = glm::vec3(i*1.5f, 0, j*1.5f);
            renderable->transform.scale = glm::vec3(0.5, 0.5, 0.5);
            renderable->mesh = new Mesh();
            renderable->mesh->loadCube();
            renderable->texture = "assets/img.png";
            children.push_back(renderable);
        }
    }

    Light* light = new Light();
    light->transform.position = glm::vec3(0, 5, 0);
    light->color = glm::vec3(1, 0, 1);
    light->mesh = new Mesh();
    light->mesh->loadCube();
    lights.push_back(light);
    
    // render loop
    while (core->run(children, lights)){
    }

    // glfw: terminate, clearing all previously allocated GLFW resources.
    glfwTerminate();
    return 0;
}