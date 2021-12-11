#include "GameObject2D.h"

GameObject2D::GameObject2D(float x, float y, float z, float pitch, float yaw, float roll, float xscale, float yscale, float zscale) {
	this->x = x;
	this->y = y;
	this->z = z;
	this->pitch = pitch;
	this->yaw = yaw;
	this->roll = roll;
	this->xScale = xscale;
	this->yScale = yscale;
	this->zScale = zscale;
	this->trans = glm::mat4(1.0f);
	this->trans = glm::translate(this->trans, glm::vec3(x, y, z));
	this->trans = glm::rotate(this->trans, glm::radians(pitch), glm::vec3(1.0f,0.0f,0.0f));
	this->trans = glm::rotate(this->trans, glm::radians(yaw), glm::vec3(0.0f, 1.0f, 0.0f));
	this->trans = glm::rotate(this->trans, glm::radians(roll), glm::vec3(0.0f, 0.0f, 1.0f));
	this->trans = glm::scale(this->trans, glm::vec3(xscale, yscale, zscale));
}

void GameObject2D::load(std::vector<GLfloat> *objVertices, std::vector<GLuint> *objIndices, std::vector<GLfloat> *VBOvector, std::vector<GLuint> *EBOvector, const char* texturePath) {

	//load image in usable tex format with stb_image
	std::string textureName = texturePath;
	std::string completePath = TEXTUREDIR + textureName;
	int texWidth, texHeight, numChannels;
	stbi_set_flip_vertically_on_load(true);
	unsigned char *data = stbi_load(completePath.c_str(), &texWidth, &texHeight, &numChannels, 0);
	

	//load image byte data to check filetype
	std::ifstream imageSignature(completePath.c_str(), std::ios::in | std::ios::binary);
	char signature[128];
	imageSignature.read(signature, 128);
	unsigned int hexsignature[128];
	
	for (int i = 0; i < 128; i++) {
		hexsignature[i] = (unsigned int)(unsigned char)(signature[i]);		//must be unsigned char to unsigned int or get weird fffff padding
	}
	
	GLenum colourSpace;

	if (hexsignature[0] == 0x89 && hexsignature[1] == 0x50 && hexsignature[2] == 0x4e && hexsignature[3] == 0x47) {			//PNG image
		colourSpace = GL_RGBA;
	}
	else if (hexsignature[0] == 0xff && hexsignature[1] == 0xd8) {				//JPG image
		colourSpace = GL_RGB;
	}
	glGenTextures(1, &(this->texture));
	glBindTexture(GL_TEXTURE_2D, this->texture);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, colourSpace, texWidth, texHeight, 0, colourSpace, GL_UNSIGNED_BYTE, data);
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
}

void GameObject2D::draw(ShaderMan* ShaderManager) {
	this->trans = glm::mat4(1.0f);
	this->trans = glm::translate(this->trans, glm::vec3(x,y,z));
	this->trans = glm::rotate(this->trans, glm::radians(pitch), glm::vec3(1.0f,0.0f,0.0f));
	this->trans = glm::rotate(this->trans, glm::radians(yaw), glm::vec3(0.0f, 1.0f, 0.0f));
	this->trans = glm::rotate(this->trans, glm::radians(roll), glm::vec3(0.0f, 0.0f, 1.0f));
	this->trans = glm::scale(this->trans, glm::vec3(xScale, yScale, zScale));
	glBindTexture(GL_TEXTURE_2D, this->texture);
	ShaderManager->setMat4f("transform", this->trans);
	glDrawElements(GL_TRIANGLES, numInds, GL_UNSIGNED_INT, (void*)(EBOindex * sizeof(GLuint)));
}

void GameObject2D::move(float x, float y, float z) {
	this->x += x;
	this->y += y;
	this->z += z;
}

void GameObject2D::scale(float x, float y, float z){
	this->xScale += xScale;
	this->yScale += yScale;
	this->zScale += zScale;
}

void GameObject2D::rotate(float pitch, float yaw, float roll){
	this->pitch -= pitch;
	this->yaw -= yaw;
	this->roll -= roll;
}
