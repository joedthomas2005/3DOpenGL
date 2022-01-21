#include "Triangle.h"

Triangle::Triangle(float x1, float y1, float z1,
				   float x2, float y2, float z2,
				   float x3, float y3, float z3,
				   float r, float g, float b,
				   std::vector<GLfloat>& VBO, std::vector<GLuint>& EBO, const char* texturePath, bool UI)
	: GameObject2D(0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,1.0f,1.0f,1.0f,UI){

	std::vector<GLfloat> verts = { x1, y1, z1,
		r, g, b, 
		0.0f,0.0f, 
		x2, y2, z2, 
		r, g, b,
		0.5f, 1.0f, 
		x3, y3, z3, 
		r, g, b, 
		1.0f, 0.0f};

	std::vector<GLuint> indices = { 0,1,2 };
	this->load(verts, indices, VBO, EBO, texturePath);
}
