#include "GameObject.h"

GameObject::GameObject(float x, float y, float z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

void GameObject::load(std::vector<GLfloat> *objVertices, std::vector<GLuint> *objIndices, std::vector<GLfloat> *VBOvector, std::vector<GLuint> *EBOvector, const char* texturePath) {
	int texWidth, texHeight, numChannels;

	unsigned char *data = stbi_load(texturePath, &texWidth, &texHeight, &numChannels, 0);

	glGenTextures(1, &(this->texture));
	glBindTexture(GL_TEXTURE_2D, this->texture);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texWidth, texHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	glGenerateMipmap(GL_TEXTURE_2D);

	stbi_image_free(data);

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
	glBindTexture(GL_TEXTURE_2D, this->texture);
	ShaderManager->setVec3f("transform", x, y, z);
	glDrawElements(GL_TRIANGLES, numInds, GL_UNSIGNED_INT, (void*)(EBOindex * sizeof(GLuint)));
}

void GameObject::move(float x, float y, float z) {
	this->x += x;
	this->y += y;
	this->z += z;
}