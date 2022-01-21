#pragma once
#include<vector>
#include<algorithm>
#include "GameObject.h"

class Mesh : public GameObject{
public:
	Mesh(float x, float y, float z, float pitch, float roll, float yaw, float width, float height, float depth, std::vector<GLfloat>* vertices, std::vector<GLuint>* indices, std::vector<GLfloat>* VBO, std::vector<GLuint>* EBO, std::vector<MeshTexture>* textures);
	void draw(ShaderMan* shader);
private:
	void load(std::vector<GLfloat>* objVertices, std::vector<GLuint>* objIndices, std::vector<GLfloat>* VBO, std::vector<GLuint>* EBO);
	std::vector<MeshTexture>* textures;
};