#include "GameObject.h"

GameObject::GameObject(float x, float y, float z, float angle, float xscale, float yscale, float zscale) {
	this->x = x;
	this->y = y;
	this->z = z;
	this->angle = angle;
	this->xScale = xscale;
	this->yScale = yscale;
	this->zScale = zscale;
	this->trans = glm::mat4(1.0f);
	this->trans = glm::translate(this->trans, glm::vec3(x, y, z));
	this->trans = glm::rotate(this->trans, glm::radians(angle), glm::vec3(0.0f,0.0f,1.0f));
	this->trans = glm::scale(this->trans, glm::vec3(xscale, yscale, zscale));
}

void GameObject::load(std::vector<GLfloat> *objVertices, std::vector<GLuint> *objIndices, std::vector<GLfloat> *VBOvector, std::vector<GLuint> *EBOvector, const char* texturePath) {

	std::string textureName = texturePath;
	std::string completePath = TEXTUREDIR + textureName;
	int texWidth, texHeight, numChannels;

	unsigned char *data = stbi_load(completePath.c_str(), &texWidth, &texHeight, &numChannels, 0);

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
	this->trans = glm::mat4(1.0f);
	this->trans = glm::translate(this->trans, glm::vec3(x,y,z));
	this->trans = glm::rotate(this->trans, glm::radians(angle), glm::vec3(0.0f,0.0f,1.0f));
	this->trans = glm::scale(this->trans, glm::vec3(xScale, yScale, zScale));
	glBindTexture(GL_TEXTURE_2D, this->texture);
	ShaderManager->setMat4f("transform", this->trans);
	glDrawElements(GL_TRIANGLES, numInds, GL_UNSIGNED_INT, (void*)(EBOindex * sizeof(GLuint)));
}

void GameObject::move(float x, float y, float z) {
	this->x += x;
	this->y += y;
	this->z += z;
}

void GameObject::scale(float x, float y, float z){
	this->xScale += xScale;
	this->yScale += yScale;
	this->zScale += zScale;
}

void GameObject::rotate(float angle){
	this->angle += angle;
}
