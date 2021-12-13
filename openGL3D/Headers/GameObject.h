#pragma once
#include <vector>
#include "ShaderMan.h"

class GameObject {
public:
	virtual void draw(ShaderMan* Shader) {};
	virtual void load(std::vector<GLfloat> *objVertices, std::vector<GLuint> *objIndices, std::vector<GLfloat> *VBOvector, std::vector<GLuint> *EBOvector, const char* texturePath) {};	
	virtual void load(std::vector<GLfloat> *objVertices, std::vector<GLuint> *objIndices, std::vector<GLfloat> *VBOvector, std::vector<GLuint> *EBOvector, const char* texturePaths[6]) {};	
};
