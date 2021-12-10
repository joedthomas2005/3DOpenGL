#pragma once
#include<vector>
#include<cmath>
#include "GameObject.h"
class Circle : public GameObject{
public:
	Circle(int numberofVerts, float width, float height,float x, float y, float z, float pitch, float yaw, float roll, float r, float g, float b, std::vector<GLfloat> *VBO, std::vector<GLuint> *EBO, const char* texturePath);
};
