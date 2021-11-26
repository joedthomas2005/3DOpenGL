#include "Circle.h"

Circle::Circle(float radius, int numberofVerts, float x, float y, float z, float r, float g, float b, std::vector<GLfloat> *VBO, std::vector<GLuint> *EBO) {
	std::vector<GLfloat> verts;
	std::vector<GLuint> inds;
	for (int i = 1; i < numberofVerts; i++) {
		inds.push_back(0);
		inds.push_back(i);
		inds.push_back(i + 1);
	}
	inds.push_back(0);
	inds.push_back(numberofVerts);
	inds.push_back(1);

	verts.push_back(0.0f);
	verts.push_back(0.0f);
	verts.push_back(0.0f);
	verts.push_back(r);
	verts.push_back(g);
	verts.push_back(b);


}