#pragma once
#include<vector>
#include<algorithm>
#include "GameObject.h"
#include "ShaderMan.h"
#include "TexUtils.h"
class Cube : public GameObject{
public:
	Cube(float x, float y, float z,
		float width, float height, float depth, 
		float pitch, float yaw, float roll, 
		float r, float g, float b, 
		std::vector<GLfloat> *VBO, std::vector<GLuint> *EBO, 
		std::vector<const char*> texturePath);
	
	Cube(float x, float y, float z,
		float width, float height, float depth,
		float pitch, float yaw, float roll,
		float r, float g, float b,
		std::vector<GLfloat> *VBO, std::vector<GLuint> *EBO,
		const char* right, const char* left, const char* top, const char* bottom, const char* front, const char* back);
	
	Cube(float x, float y, float z,
		float width, float height, float depth,
		float pitch, float yaw, float roll,
		float r, float g, float b,
		std::vector<GLfloat> *VBO, std::vector<GLuint> *EBO,
		const char* texturePath);
	void specialcubemethod();
	void load(std::vector<GLfloat> *objVertices, std::vector<GLuint> *objIndices, std::vector<GLfloat> *VBOvector, std::vector<GLuint> *EBOvector, std::vector<const char*> texPaths);

	void draw(ShaderMan* Shader);
};
