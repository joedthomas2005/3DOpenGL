#pragma once
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<vector>
#include<algorithm>
#include<iostream>

#include "ShaderMan.h"

class GameObject {
public:
	GameObject();
	void move(float x, float y, float z);
	void draw(ShaderMan* shaderManager);
protected:
	void load(std::vector<GLfloat> *objVertices, std::vector<GLuint> *objIndices, std::vector<GLfloat> *VBOvector, std::vector<GLuint> *EBOvector);
private:
	std::vector<GLfloat>* VBO;
	std::vector<GLuint>* EBO;
	std::vector<GLfloat>* objVertices;
	std::vector<GLuint>* objIndices;
	float x, y, z;
	int EBOindex;
	int numVerts;
	int numInds;
	bool checkBool;
};