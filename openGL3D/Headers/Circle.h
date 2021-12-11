#pragma once
#include<vector>
#include<cmath>
#include "GameObject2D.h"
class Circle : public GameObject2D{
public:
	Circle(int numberofVerts, float width, float height,float x, float y, float z, float pitch, float yaw, float roll, float r, float g, float b, std::vector<GLfloat> *VBO, std::vector<GLuint> *EBO, const char* texturePath);
};
