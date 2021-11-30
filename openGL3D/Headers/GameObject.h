#pragma once
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
#include "stb_image.h"
#include "ShaderMan.h"

class GameObject {
public:
	GameObject(float x, float y, float z);
	void move(float x, float y, float z);
	void draw(ShaderMan* shaderManager);
protected:
	void load(std::vector<GLfloat> *objVertices, std::vector<GLuint> *objIndices, std::vector<GLfloat> *VBOvector, std::vector<GLuint> *EBOvector, const char* texturePath);
private:
	std::vector<GLfloat>* VBO;
	std::vector<GLuint>* EBO;
	std::vector<GLfloat>* objVertices;
	std::vector<GLuint>* objIndices;
	unsigned int texture;
	float x, y, z;
	int EBOindex;
	int numVerts;
	int numInds;
	std::string TEXTUREDIR = "Resources/Textures/";
};