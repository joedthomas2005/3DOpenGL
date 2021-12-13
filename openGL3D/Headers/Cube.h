#pragma once
#include<vector>
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
		const char* texturePath);


	void load(std::vector<GLfloat> *objVertices, std::vector<GLuint> *objIndices, std::vector<GLfloat> *VBOvector, std::vector<GLuint> *EBOvector, const char* texturePaths[6]);

	void draw(ShaderMan* Shader);
};
