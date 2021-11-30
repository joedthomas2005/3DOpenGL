#pragma once
#include<vector>
#include "GameObject.h"
class Triangle : public GameObject {
public:
	Triangle(float x1, float y1, float z1,
		float x2, float y2, float z2,
		float x3, float y3, float z3,
		float r, float g, float b,
		std::vector<GLfloat> *VBO, std::vector<GLuint> *EBO, const char* texturePath);
};