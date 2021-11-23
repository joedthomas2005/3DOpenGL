#pragma once
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<vector>
#include<algorithm>
#include "ShaderMan.h"
class GameObject {
public:
	GameObject(const std::vector<GLfloat> *objVertices, const std::vector<GLfloat> *objIndices, std::vector<GLfloat> *VBOvector, std::vector<GLint> *EBOvector);
	void draw(ShaderMan shaderManager);
	void move(float x, float y, float z);
private:
	std::vector<GLfloat>* VBO;
	std::vector<GLint>* EBO;
	const std::vector<GLfloat>* objVertices;
	const std::vector<GLfloat>* objIndices;

}