#pragma once
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<glm/glm/glm.hpp>
#include<glm/glm/gtc/matrix_transform.hpp>
#include<glm/glm/gtc/type_ptr.hpp>
#include<glm/glm/gtx/string_cast.hpp>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
#include<fstream>
#include "stb_image.h"
#include "ShaderMan.h"
#include "GameObject.h"
#include "TexUtils.h"
class GameObject2D : public GameObject{
public:
	GameObject2D(float x, float y, float z, float pitch, float yaw, float roll, float xscale, float yscale, float zscale, bool UI);
	void draw(ShaderMan& shaderManager);
protected:
	void load(std::vector<GLfloat> &objVertices, std::vector<GLuint> &objIndices, std::vector<GLfloat> &VBOvector, std::vector<GLuint> &EBOvector, const char* texturePath);
};
