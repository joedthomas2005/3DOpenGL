#pragma once
#include<vector>
#include "GameObject2D.h"
class Cube : public GameObject2D{
public:
	Cube(float x, float y, float z,
		float width, float height, float depth, 
		float pitch, float yaw, float roll, 
		float r, float g, float b, 
		std::vector<GLfloat> *VBO, std::vector<GLuint> *EBO, 
		const char* texturePath);
};