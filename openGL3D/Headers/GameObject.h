#pragma once
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
#include "stb_image.h"
#include "ShaderMan.h"

class GameObject {
public:
	GameObject(float x, float y, float z, float angle, float xscale, float yscale, float zscale);
	void move(float x, float y, float z);
	void rotate(float angle);
	void scale(float x, float y, float z);
	void draw(ShaderMan* shaderManager);
protected:
	void load(std::vector<GLfloat> *objVertices, std::vector<GLuint> *objIndices, std::vector<GLfloat> *VBOvector, std::vector<GLuint> *EBOvector, const char* texturePath);
private:
	std::vector<GLfloat>* VBO;
	std::vector<GLuint>* EBO;
	std::vector<GLfloat>* objVertices;
	std::vector<GLuint>* objIndices;
	unsigned int texture;
	glm::mat4 trans;
	int EBOindex;
	int numVerts;
	int numInds;
	float x,y,z,xScale,yScale,zScale,angle;
	std::string TEXTUREDIR = "Resources/Textures/";
};
