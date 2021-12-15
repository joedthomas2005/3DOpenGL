#pragma once
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<fstream>
#include<string>
#include<iostream>
#include<glm/glm/glm.hpp>
#include<glm/glm/gtc/matrix_transform.hpp>
#include<glm/glm/gtc/type_ptr.hpp>
#include "WindowMan.h"

class ShaderMan {
private:
	glm::mat4 view;
	glm::mat4 projection;
	glm::mat4 ortho;
	Window* window;
	const std::string SHADERDIR = "Resources/Shaders/";
public:
	GLuint ID;
	ShaderMan(const char* vertShaderPath, const char* fragShaderPath, Window* window);
	void use();
	void setVec3f(const char* name, GLfloat x, GLfloat y, GLfloat z) const;
	void setMat4f(const char* name, glm::mat4 data) const;
	void setBool(const char* name, bool data) const;
};
