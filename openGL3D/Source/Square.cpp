#include "Square.h"

Square::Square(float width, float height,
	float x, float y, float z,
	float pitch, float yaw, float roll,
	float r, float g, float b,
	std::vector<GLfloat>* VBO, std::vector<GLuint>* EBO, const char* texturePath)

	: GameObject2D(x, y, z, pitch, yaw, roll, width, height, 1.0f){

	std::vector<GLfloat> verts;
	
	std::vector<GLuint> indices = { 2,3,1, 2,1,0 };
	verts.reserve(24);
	
	for (int w = 1; w >= -1; w -= 2) {
		for (int h = 1; h >= -1; h -= 2) {
			verts.push_back(w * 0.25);
			verts.push_back(h * 0.25);
			verts.push_back(0);
			verts.push_back(r);
			verts.push_back(g);
			verts.push_back(b);
			if (w < 0.0) {
				verts.push_back(0.0f);
			}
			else {
				verts.push_back(1.0f);
			}
			if (h < 0.0f) {
				verts.push_back(0.0f);
			}
			else {
				verts.push_back(1.0f);
			}
		}
	}

	this->load(&verts, &indices, VBO, EBO, texturePath);
}
