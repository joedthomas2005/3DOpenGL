#pragma once
#include<vector>
#include "GameObject.h"

class Circle {
	Circle(float radius, int numberofVerts, float x, float y, float z, float r, float g, float b, std::vector<GLfloat> *VBO, std::vector<GLuint> *EBO);
};