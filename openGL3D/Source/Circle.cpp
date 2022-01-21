#include "Circle.h"

Circle::Circle(int numberofVerts,
	float width, float height,
	float x, float y, float z,
	float pitch, float yaw, float roll,
	float r, float g, float b,
	std::vector<GLfloat> &VBO, std::vector<GLuint> &EBO, const char* texturePath, bool UI)
	: GameObject2D(x,y,z, pitch, yaw, roll, width, height, 1.0f, UI) {
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
	verts.push_back(0.5f);
	verts.push_back(0.5f);

	const double PI = std::atan(1) * 4.0;
	for (GLfloat i = 0; i < 360; i += 360/numberofVerts) {
		verts.push_back(0.25 * std::cos(i * (PI/180.0f)));
		verts.push_back(0.25 * std::sin(i * (PI/180.0f)));
		verts.push_back(0);
		verts.push_back(r);
		verts.push_back(g);
		verts.push_back(b);
		GLfloat textureX = 0.5f * std::cos(i * (PI / 180.0f));
		GLfloat textureY = 0.5f * std::sin(i * (PI / 180.0f));
		verts.push_back(textureX + 0.5f);
		verts.push_back(textureY + 0.5f);
	}

	this->load(verts, inds, VBO, EBO, texturePath);

}
