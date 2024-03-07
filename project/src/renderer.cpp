#include "renderer.h"

Renderer::Renderer() {
}

void Renderer::render(Renderable *renderable, Shader *shader, Camera *camera, Light* light) {
	Transform transform = renderable->transform;
	Material material = renderable->material;
	Mesh* mesh = renderable->mesh;

	// set positions, rotation and scale
	glm::mat4 model = glm::mat4(1.0f);
	model = glm::scale(model, transform.scale);
	model = glm::translate(model, transform.position);
	model = glm::rotate(model, (float)0, glm::vec3(1.0f, 1.0f, 0.0f));

	// set perspective
	glm::mat4 view = glm::lookAt(camera->position, camera->position + camera->front, camera->up);
	glm::mat4 projection = glm::perspective(45.0f, (GLfloat)800 / (GLfloat)600, 0.1f, 100.0f);

	// pass data to shader
	shader->Use();
	shader->setMat4("model", model);
	shader->setMat4("view", view);
	shader->setMat4("projection", projection);

	shader->setVec3("ourViewPos", camera->position);

	shader->setVec3("ourLight.position", light->transform.position);
	shader->setVec3("ourLight.color", light->color);
	shader->setVec3("ourLight.ambient", light->ambient);
	shader->setVec3("ourLight.diffuse", light->diffuse);
	shader->setVec3("ourLight.specular", light->specular);

	shader->setVec3("ourMaterial.ambient", material.ambient);
	shader->setVec3("ourMaterial.diffuse", material.diffuse);
	shader->setVec3("ourMaterial.specular", material.specular);
	shader->setFloat("ourMaterial.shininess", material.shininess);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, ResourceManager::getInstance()->getTexture(renderable->texture, 0, 0));

	// draw the mesh
	glBindVertexArray(mesh->VAO);
	glDrawArrays(GL_TRIANGLES, 0, mesh->drawsize);
	glBindVertexArray(0);
}

void Renderer::renderLight(Light *light, Shader *shader, Camera *camera) {
	Transform transform = light->transform;
	Mesh* mesh = light->mesh;

	// set positions, rotation and scale
	glm::mat4 model = glm::mat4(1.0f);
	model = glm::scale(model, transform.scale);
	model = glm::translate(model, transform.position);
	model = glm::rotate(model, (float)0, glm::vec3(1.0f, 1.0f, 0.0f));

	// set perspective
	glm::mat4 view = glm::lookAt(camera->position, camera->position + camera->front, camera->up);
	glm::mat4 projection = glm::perspective(45.0f, (GLfloat)800 / (GLfloat)600, 0.1f, 100.0f);

	// pass data to shader
	shader->Use();
	shader->setMat4("model", model);
	shader->setMat4("view", view);
	shader->setMat4("projection", projection);
	
	shader->setVec3("inColor", light->color);


	// draw the mesh
	glBindVertexArray(mesh->VAO);
	glDrawArrays(GL_TRIANGLES, 0, mesh->drawsize);
	glBindVertexArray(0);
}
