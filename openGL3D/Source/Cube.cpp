#include "Cube.h"

Cube::Cube(float x, float y, float z,
	float width, float height, float depth,
	float pitch, float yaw, float roll,
	float r, float g, float b,
	std::vector<GLfloat>* VBO, std::vector<GLuint>* EBO,
	const char* texturePath) 
	:GameObject2D(x, y, z, pitch, yaw, roll, width, height, depth)
{
	std::vector<GLuint> indices = {
		6, 4, 0, 0, 2, 6,		//FRONT
		0, 1, 2, 2, 3, 1,		//RIGHT
		7, 5, 1, 1, 3, 7,		//BACK
		4, 5, 6, 6, 7, 5,		//LEFT
		4, 0, 5, 5, 1, 0,		//TOP
		6, 7, 2, 2, 3, 7		//BOTTOM
	};
	std::vector<GLfloat> verts;
	
	/**
	TOP RIGHT FRONT 0
	TOP RIGHT BACK 1
	BOTTOM RIGHT FRONT 2
	BOTTOM RIGHT BACK 3 
	TOP LEFT FRONT 4
	TOP LEFT BACK 5 
	BOTTOM LEFT FRONT 6
	BOTTOM LEFT BACK 7
	**/
	for (int w = 1; w >= -1; w -= 2) {
		for (int h = 1; h >= -1; h -= 2) {
			for (int d = 1; d >= -1; d -= 2) {
				verts.push_back(w * 0.25f);
				verts.push_back(h * 0.25f);
				verts.push_back(d * 0.25f);
				verts.push_back(r);
				verts.push_back(g);
				verts.push_back(b);
				if (w < 0.0f) {
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
	}
	std::cout << "CUBE VERTS" << std::endl;
	for (GLfloat v : verts) {
		std::cout << v << ",";
	}
	std::cout << std::endl;
	
	this->load(&verts, &indices, VBO, EBO, texturePath);
	

}