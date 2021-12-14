#pragma once
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<vector>
#include<iostream>
class BufferManager {
public:
	BufferManager(std::vector<GLfloat> Vertices, std::vector<GLuint> Indices);
	void Bind();
private:
	unsigned int VAO, VBO, EBO;
	std::vector<GLfloat> vertexData;
	std::vector<GLuint> indexData;
};
