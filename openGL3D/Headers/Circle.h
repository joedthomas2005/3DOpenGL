#pragma once
#include<vector>
#include<cmath>
#include "GameObject.h"
class Circle : public GameObject{
public:
	Circle(float width, float height, int numberofVerts, float x, float y, float z, float r, float g, float b, float angle, std::vector<GLfloat> *VBO, std::vector<GLuint> *EBO, const char* texturePath);
};
