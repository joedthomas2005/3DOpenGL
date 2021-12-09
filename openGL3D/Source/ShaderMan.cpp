#include "ShaderMan.h"

ShaderMan::ShaderMan(const char* vertShaderPath, const char* fragShaderPath) {
	std::string vertShaderName = vertShaderPath;
	std::string fragShaderName = fragShaderPath;
	std::string completeVertPath = SHADERDIR + vertShaderName;
	std::string completeFragPath = SHADERDIR + fragShaderName;
	std::ifstream fileStream;

	std::string vertString;
	std::string fragString;
	fileStream.open(completeVertPath.c_str());
	vertString = std::string((std::istreambuf_iterator<char>(fileStream)), std::istreambuf_iterator<char>());
	const char* vertShader = vertString.c_str();
	fileStream.close();
	fileStream.open(completeFragPath.c_str());
	fragString = std::string((std::istreambuf_iterator<char>(fileStream)), std::istreambuf_iterator<char>());
	const char* fragShader = fragString.c_str();
	fileStream.close();

	GLuint vShader, fShader;
	char infoLog[512];
	int success;

	vShader = glCreateShader(GL_VERTEX_SHADER);
	fShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(vShader, 1, &vertShader, NULL);
	glShaderSource(fShader, 1, &fragShader, NULL);
	glCompileShader(vShader);
	glGetShaderiv(vShader, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(vShader, 512, NULL, infoLog);
		std::cout << "ERROR SHADER FRAGMENT COMPILATION FAILED\n" << infoLog << std::endl;
	}
	glCompileShader(fShader);
	glGetShaderiv(fShader, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(fShader, 512, NULL, infoLog);
		std::cout << "ERROR SHADER FRAGMENT COMPILATION FAILED\n" << infoLog << std::endl;
	}

	this->ID = glCreateProgram();
	glAttachShader(ID, vShader);
	glAttachShader(ID, fShader);
	glLinkProgram(ID);
	glGetProgramiv(ID, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(ID, 512, NULL, infoLog);
		std::cout << "ERROR SHADING LINKING FAILED\n" << infoLog << std::endl;
	}
	glDeleteShader(vShader);
	glDeleteShader(fShader);
}

void ShaderMan::use() {
	glUseProgram(ID);
}

void ShaderMan::setVec3f(const char* name, GLfloat x, GLfloat y, GLfloat z) const {
	glUniform3f(glGetUniformLocation(ID, name), x, y, z);
}

void ShaderMan::setMat4f(const char* name, glm::mat4 data) const{
	glUniformMatrix4fv(glGetUniformLocation(ID, name), 1, GL_FALSE, glm::value_ptr(data));
}
