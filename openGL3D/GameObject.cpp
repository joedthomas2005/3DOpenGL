#include "GameObject.h"

GameObject::GameObject(const std::vector<GLfloat> *objVertices, const std::vector<GLfloat> *objIndices, std::vector<GLfloat> *VBOvector, std::vector<GLint> *EBOvector) {
	this->VBO = VBOvector;
	this->EBO = EBOvector;
	this->objIndices = objIndices;
	this->objVertices = objVertices;

	VBO->reserve(objVertices->size());
	EBO->reserve(objIndices->size());
	int EBOvertexoffset = *std::max_element(EBO->begin(), EBO->end());
}