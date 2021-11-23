#pragma once
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<fstream>
#include<string>

class ShaderMan {
public:
	GLuint ID;
	ShaderMan(const char* vertShaderPath, const char* fragShaderPath);
	void use();
	void setVec3f(const char* name, GLfloat x, GLfloat y, GLfloat z) const;
};