#include "shader.h"

Shader::Shader(const GLchar* vertexPath, const GLchar* fragmentPath) {
	char *vertexShaderSource = "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\0";
	char *fragmentShaderSource = "#version 330 core\n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
    "}\n\0";
	// error info
	GLint success;
	GLchar infoLog[512];

	// get vertex shader code
	std::string VertexShaderCode;
	std::ifstream VertexShaderStream(vertexPath, std::ios::in);
	if (VertexShaderStream.is_open()) {
		std::string Line = "";
		while (getline(VertexShaderStream, Line)) {
			VertexShaderCode += "\n" + Line;
		}
		VertexShaderStream.close();
	}
	const GLchar* VertexSourcePointer = VertexShaderCode.c_str();

	// set vertexshader
	GLuint vertexShader;
	vertexShader = glCreateShader(GL_VERTEX_SHADER);

	glShaderSource(vertexShader, 1, &VertexSourcePointer, NULL);
	glCompileShader(vertexShader);

	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

	if (!success) {
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
	}
	else {
		std::cout << "loaded: 'vertexShader'" << std::endl;
	}

	// get fragment shader code
	std::string FragmentShaderCode;
	std::ifstream FragmentShaderStream(fragmentPath, std::ios::in);
	if (FragmentShaderStream.is_open()) {
		std::string Line = "";
		while (getline(FragmentShaderStream, Line)) {
			FragmentShaderCode += "\n" + Line;
		}
		FragmentShaderStream.close();
	}
	const GLchar* FragmentSourcePointer = FragmentShaderCode.c_str();

	// set fragmentshader
	GLuint fragmentShader;
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

	glShaderSource(fragmentShader, 1, &FragmentSourcePointer, NULL);
	glCompileShader(fragmentShader);

	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
	}
	else {
		std::cout << "loaded: 'fragmentShader'" << std::endl;
	}

	// set shader program
	this->program = glCreateProgram();

	glAttachShader(this->program, vertexShader);
	glAttachShader(this->program, fragmentShader);
	glLinkProgram(this->program);

	// load program
	glGetProgramiv(this->program, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(this->program, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::PROGRAM::COMPILATION_FAILED [" << infoLog << "]" << std::endl;
	}
	else {
		std::cout << "loaded: 'shaderProgram'" << std::endl;
	}

	// delete shaders
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

void Shader::Use() {
	glUseProgram(this->program);
}

// set mat4 in shader
void Shader::setMat4(const char* name, glm::mat4 value) {
	GLint uniform = glGetUniformLocation(this->program, name);
	glUniformMatrix4fv(uniform, 1, GL_FALSE, glm::value_ptr(value));
}

// set vec3 in shader
void Shader::setVec3(const char* name, glm::vec3 value) {
	GLint uniform = glGetUniformLocation(this->program, name);
	glUniform3f(uniform, value.x, value.y, value.z);
}

// set float in shader
void Shader::setFloat(const char * name, float value){
	GLint uniform = glGetUniformLocation(this->program, name);
	glUniform1f(uniform, value);
}

// set int in shader
void Shader::setInt(const char * name, float value) {
	GLint uniform = glGetUniformLocation(this->program, name);
	glUniform1d(uniform, value);
}

// set bool in shader
void Shader::setBool(const char * name, bool value) {
	GLint uniform = glGetUniformLocation(this->program, name);
	glUniform1i(uniform, (value ? 1 : 0));
}