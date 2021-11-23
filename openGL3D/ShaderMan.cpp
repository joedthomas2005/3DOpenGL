#include "ShaderMan.h"

ShaderMan::ShaderMan(const char* vertShaderPath, const char* fragShaderPath) {

	std::ifstream fileStream;

	std::string inputString;

	fileStream.open(vertShaderPath);
	inputString = std::string((std::istreambuf_iterator<char>(fileStream)), std::istreambuf_iterator<char>());
	const char* vertShader = inputString.c_str();
	fileStream.close();
	fileStream.open(fragShaderPath);
	inputString = std::string((std::istreambuf_iterator<char>(fileStream)), std::istreambuf_iterator<char>());
	const char* fragShader = inputString.c_str();
	fileStream.close();

	GLuint vShader, fShader;
	vShader = glCreateShader(GL_VERTEX_SHADER);
	fShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(vShader, 1, &vertShader, NULL);
	glShaderSource(fShader, 1, &fragShader, NULL);
	glCompileShader(vShader);
	glCompileShader(fShader);

	this->ID = glCreateProgram();
	glAttachShader(ID, vShader);
	glAttachShader(ID, fShader);
	glLinkProgram(ID);
	
	glDeleteShader(vShader);
	glDeleteShader(fShader);
}

void ShaderMan::use() {
	glUseProgram(ID);
}

void ShaderMan::setVec3f(const char* name, GLfloat x, GLfloat y, GLfloat z) const {
	glUniform3f(glGetUniformLocation(ID, name), x, y, z);
}