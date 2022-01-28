#include "Mesh.h"



Mesh::Mesh::Mesh(std::vector<GLfloat> &vertices, std::vector<GLuint>& indices, std::vector<Texture>& textures, std::vector<GLfloat>& VBO, std::vector<GLuint>& EBO) {
	this->numInds = indices.size();
	this->EBOindex = EBO.size();

	int EBOvertexoffset;

	if (EBO.size() > 0) {
		EBOvertexoffset = *std::max_element(EBO.begin(), EBO.end()) + 1;
	}
	else {
		EBOvertexoffset = 0;
	}

	for (int i = 0; i < vertices.size(); i++) {
		vertices.push_back(vertices[i]);
	}

	for (int i = 0; i < indices.size(); i++) {
		indices.push_back(indices[i] + EBOvertexoffset);
	}


};

void Mesh::Mesh::Draw(ShaderMan& shader) {

};



