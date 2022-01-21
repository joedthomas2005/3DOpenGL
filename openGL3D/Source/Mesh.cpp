#include "Mesh.h"

Mesh::Mesh(float x, float y, float z, float pitch, float roll, float yaw, float width, float height, float depth, std::vector<GLfloat>* vertices, std::vector<GLuint>* indices, std::vector<GLfloat>* VBO, std::vector<GLuint>* EBO, std::vector<MeshTexture>* textures) 
	: GameObject(x,y,z,pitch,yaw,roll,width,height,depth,false){

	this->objIndices = indices;
	this->objVertices = vertices;
	this->EBO = EBO;
	this->VBO = VBO;

	this->load(vertices, indices, VBO, EBO);

}

void Mesh::load(std::vector<GLfloat>* vertices, std::vector<GLuint>* indices, std::vector<GLfloat>* VBO, std::vector<GLuint>* EBO) {
	this->VBO = VBO;
	this->EBO = EBO;
	this->objIndices = objIndices;
	this->objVertices = objVertices;
	VBO->reserve(objVertices->size());
	EBO->reserve(objIndices->size());

	int EBOvertexoffset;
	if (EBO->size() > 0) {
		EBOvertexoffset = *std::max_element(EBO->begin(), EBO->end()) + 1;
	}
	else {
		EBOvertexoffset = 0;
	}


	this->EBOindex = EBO->size();

	for (int i = 0; i < objIndices->size(); i++) {
		EBO->push_back((*objIndices)[i] + EBOvertexoffset);
	}

	for (int i = 0; i < objVertices->size(); i++) {
		VBO->push_back((*objVertices)[i]);
	}

	this->numVerts = objVertices->size();
	this->numInds = objIndices->size();
	this->genTransformMatrix();
}