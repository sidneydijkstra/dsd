#include "core.h"

Core::Core()
{
	this->createWindow();

    input = new Input(_window);
    camera = new Camera();
	renderer = new Renderer();
	normalShader = new Shader("shaders/normal.vert", "shaders/normal.frag");
	lightShader = new Shader("shaders/light.vert", "shaders/light.frag");
}

Core::~Core() {
	delete normalShader;
	delete lightShader;
	delete renderer;
	delete camera;
	delete input;
}

bool Core::run(std::vector<Renderable*> children, std::vector<Light*> lights) {
    this->calculateDeltaTime();
	this->calculateFPS();
	
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glEnable(GL_DEPTH_TEST);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Update
	camera->move(deltaTime, input);

	// Render
	for (Light* light : lights) {
		renderer->renderLight(light, lightShader, camera);
	}
	for (Renderable* renderable : children) {
		renderer->render(renderable, normalShader, camera, lights[0]);
	}
		
	glfwSwapBuffers(_window);
	glfwPollEvents();
	
	// Check if escape is pressed to close window
    if(glfwGetKey(_window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(_window, true);

    if(glfwGetKey(_window, GLFW_KEY_G) == GLFW_PRESS){
		delete normalShader;
		normalShader = new Shader("shaders/normal.vert", "shaders/normal.frag");
		delete lightShader;
		lightShader = new Shader("shaders/light.vert", "shaders/light.frag");
	}

	return !glfwWindowShouldClose(_window);
}

void Core::createWindow() {
	// initialize glfw
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // create glfw window
    _window = glfwCreateWindow(Config::WIDTH, Config::HEIGHT, "DSD", NULL, NULL);
    if (_window == NULL) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return;
    }
	
	glEnable(GL_DEPTH_TEST);

	// Set window to current context
    glfwMakeContextCurrent(_window);
	// Set framebuffer size callback
    glfwSetFramebufferSizeCallback(_window, [](GLFWwindow* window, int width, int height) {
		glViewport(0, 0, width, height);
	});
    
	// Set input mode to disabled cursor
	glfwSetInputMode(_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    // Initializing GLEW
	glewExperimental = GL_FALSE;
	if (glewInit() != GLEW_OK){
		std::cout << "Failed to initialize GLEW" << std::endl;
	}
}

void Core::calculateDeltaTime()
{
    GLfloat currentFrame = glfwGetTime();
	deltaTime = currentFrame - lastFrame;
	lastFrame = currentFrame;
}

void Core::calculateFPS() {
	currentTime = glfwGetTime();
	fps++;
	if (currentTime - lastTime >= 1) {
		std::cout << "fps: " << fps << std::endl;

		lastTime = glfwGetTime();
		fps = 0;
	}
}
