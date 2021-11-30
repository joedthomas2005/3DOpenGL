#pragma once
#include<vector>
#include "GameObject.h"
class Square : public GameObject{
	public:
		Square(float width, float height, float x, float y, float z, float r, float g, float b, std::vector<GLfloat>* VBO, std::vector<GLuint>* EBO, const char* texturePath);
};