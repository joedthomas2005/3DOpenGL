#include "Square.h"

Square::Square(float width, float height, float r, float g, float b, std::vector<GLfloat>* VBO, std::vector<GLuint>* EBO) {
	std::vector<GLfloat> verts;
	
	std::vector<GLuint> indices = { 2,3,1, 2,1,0 };
	verts.reserve(24);
	
	for (int w = 1; w >= -1; w -= 2) {
		for (int h = 1; h >= -1; h -= 2) {
			verts.push_back(0 + w * (width / 2));
			verts.push_back(0 + h * (height / 2));
			verts.push_back(0);
			verts.push_back(r);
			verts.push_back(g);
			verts.push_back(b);
		}
	}

	this->load(&verts, &indices, VBO, EBO);
}