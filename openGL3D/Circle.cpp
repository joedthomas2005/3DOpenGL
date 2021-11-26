#include "Circle.h"

Circle::Circle(float radius, int numberofVerts, float x, float y, float z, float r, float g, float b, std::vector<GLfloat> *VBO, std::vector<GLuint> *EBO) : GameObject(x,y,z) {
	std::vector<GLfloat> verts;
	std::vector<GLuint> inds;

	verts.reserve(6 * numberofVerts);
	inds.reserve(3 * numberofVerts);

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
	const double PI = atan(1) * 4.0;
	for (GLfloat i = 0; i < 360; i += 360/numberofVerts) {
		std::cout << i << std::endl;
		verts.push_back(radius * cos(i * (PI/180.0f)));
		verts.push_back(radius * sin(i * (PI/180.0f)));
		verts.push_back(0);
		verts.push_back(r);
		verts.push_back(g);
		verts.push_back(b);
	}

	this->load(&verts, &inds, VBO, EBO);

}