#pragma once
#include <vector>
#include <string>
#include <glm/glm/glm.hpp>
#include <glm/glm/gtc/matrix_transform.hpp>
#include <glm/glm/gtc/type_ptr.hpp>
#include "ShaderMan.h"
#include "TexUtils.h"

class GameObject {
public:
	void GameObject(float x, float y, float pitch, float yaw, float roll, float xscale, float yscale, float zscale);
	virtual void draw(ShaderMan* Shader) {};
	virtual void load(std::vector<GLfloat> *objVertices, std::vector<GLuint> *objIndices, std::vector<GLfloat> *VBOvector, std::vector<GLuint> *EBOvector, const char* texturePath) {};	
	virtual void load(std::vector<GLfloat> *objVertices, std::vector<GLuint> *objIndices, std::vector<GLfloat> *VBOvector, std::vector<GLuint> *EBOvector, std::vector<const char*> texturePaths) {};	

	void move(float x, float y, float z);
	void rotate(float pitch, float yaw, float roll);
	void scale(float x, float y, float z);
	void genTransformMatrix();
	std::vector<GLuint>* EBO, objIndices;
	std::vector<GLfloat>* VBO, objVertices;
	glm::mat4 trans;
	unsigned int texture;
	int EBOindex, numVerts, numInds;
	float x, y z, pitch, yaw, roll, xScale, yScale, zScale;
protected:
	std::string TEXTUREDIR = "Resources/Textures";
	
};	
