#include "GameObject.h"

GameObject::GameObject() {
	this->checkBool = false;
}

void GameObject::load(std::vector<GLfloat> *objVertices, std::vector<GLuint> *objIndices, std::vector<GLfloat> *VBOvector, std::vector<GLuint> *EBOvector) {
	std::cout << "Loading Object" << std::endl;
	this->VBO = VBOvector;
	this->EBO = EBOvector;
	this->objIndices = objIndices;
	this->objVertices = objVertices;
	std::cout << "There are " << this->objIndices->size() << " indices" << std::endl;
	VBO->reserve(objVertices->size());
	EBO->reserve(objIndices->size());

	int EBOvertexoffset;
	if (EBO->size() > 0) {
		EBOvertexoffset = *std::max_element(EBO->begin(), EBO->end());
	}
	else {
		EBOvertexoffset = 0;
	}

	std::cout << "Object vertex offset " << EBOvertexoffset << std::endl;
	
	this->EBOindex = EBO->size();

	std::cout << "EBO Index " << this->EBOindex << std::endl;

	for (int i = 0; i < objIndices->size(); i++) {
		EBO->push_back((*objIndices)[i] + EBOvertexoffset);
	}

	for (int i = 0; i < objVertices->size(); i++) {
		VBO->push_back((*objVertices)[i]);
	}
	
	std::cout << "Object Loaded" << std::endl;
	this->numVerts = objVertices->size();
	this->numInds = objIndices->size();
	this->checkBool = true;
}

void GameObject::draw(ShaderMan* ShaderManager) {
	ShaderManager->setVec3f("transform", x, y, z);
	//std::cout << "DRAWING " << numVerts << " INDICES FROM " << EBOindex << std::endl;
	glDrawElements(GL_TRIANGLES, numVerts, GL_UNSIGNED_INT, (void*)(EBOindex * sizeof(GLuint)));
}

void GameObject::move(float x, float y, float z) {
	this->x += x;
	this->y += y;
	this->z += z;
}