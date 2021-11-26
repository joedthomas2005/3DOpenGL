#include "GameObject.h"

GameObject::GameObject(float x, float y, float z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

void GameObject::load(std::vector<GLfloat> *objVertices, std::vector<GLuint> *objIndices, std::vector<GLfloat> *VBOvector, std::vector<GLuint> *EBOvector) {
	this->VBO = VBOvector;
	this->EBO = EBOvector;
	this->objIndices = objIndices;
	this->objVertices = objVertices;
	VBO->reserve(objVertices->size());
	EBO->reserve(objIndices->size());

	int EBOvertexoffset;
	if (EBO->size() > 0) {
		EBOvertexoffset = *std::max_element(EBO->begin(), EBO->end()) + 1;
		std::cout << "INDICES INCREASED BY " << EBOvertexoffset << std::endl;
	}
	else {
		EBOvertexoffset = 0;
	}

	
	this->EBOindex = EBO->size();
	std::cout << "STARTS AT INDEX " << EBOindex << std::endl;

	for (int i = 0; i < objIndices->size(); i++) {
		EBO->push_back((*objIndices)[i] + EBOvertexoffset);
	}

	for (int i = 0; i < objVertices->size(); i++) {
		VBO->push_back((*objVertices)[i]);
	}
	
	this->numVerts = objVertices->size();
	this->numInds = objIndices->size();
}

void GameObject::draw(ShaderMan* ShaderManager) {
	ShaderManager->setVec3f("transform", x, y, z);
	glDrawElements(GL_TRIANGLES, numInds, GL_UNSIGNED_INT, (void*)(EBOindex * sizeof(GLuint)));
}

void GameObject::move(float x, float y, float z) {
	this->x += x;
	this->y += y;
	this->z += z;
}