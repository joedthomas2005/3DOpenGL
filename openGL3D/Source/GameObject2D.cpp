#include "GameObject2D.h"

GameObject2D::GameObject2D(float x, float y, float z,
	float pitch, float yaw, float roll,
	float xscale, float yscale, float zscale,
	bool UI)
	: GameObject(x, y, z,
		pitch, yaw, roll,
		xscale, yscale, zscale,
		UI) {}

void GameObject2D::load(std::vector<GLfloat> &objVertices, std::vector<GLuint> &objIndices, std::vector<GLfloat> &VBOvector, std::vector<GLuint> &EBOvector, const char* texturePath) {

	std::string textureName = texturePath;
	std::string completePath = TEXTUREDIR + textureName;
	int texWidth, texHeight, numChannels;
	unsigned char* data = TexUtils::loadImage(completePath, &texWidth, &texHeight, &numChannels);		
	
	GLenum colourSpace = TexUtils::colourSpace(completePath);


	glGenTextures(1, &(this->texture));
	glBindTexture(GL_TEXTURE_2D, this->texture);


	glTexImage2D(GL_TEXTURE_2D, 0, colourSpace, texWidth, texHeight, 0, colourSpace, GL_UNSIGNED_BYTE, data);
	glGenerateMipmap(GL_TEXTURE_2D);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);


	TexUtils::freeTexData(data);

	int err = glGetError();
	if (err) {
		std::cout << "Problem Loading 2D Texture: Error Code "<<err<< std::endl;
	}


	VBOvector.reserve(objVertices.size());
	EBOvector.reserve(objIndices.size());

	int EBOvertexoffset;
	if (EBOvector.size() > 0) {
		EBOvertexoffset = *std::max_element(EBOvector.begin(), EBOvector.end()) + 1;
	}
	else {
		EBOvertexoffset = 0;
	}

	
	this->EBOindex = EBOvector.size();

	for (int i = 0; i < objIndices.size(); i++) {
		EBOvector.push_back(objIndices[i] + EBOvertexoffset);
	}

	for (int i = 0; i < objVertices.size(); i++) {
		VBOvector.push_back(objVertices[i]);
	}
	
	this->numVerts = objVertices.size();
	this->numInds = objIndices.size();
	this->genTransformMatrix();
}

void GameObject2D::draw(ShaderMan& ShaderManager) {
	this->genTransformMatrix();
	//std::cout<<glm::to_string(this->trans)<<std::endl;
	ShaderManager.setBool("isCube", false);
	ShaderManager.setBool("isUI", UI);
	glBindTexture(GL_TEXTURE_2D, this->texture);
	glBindTexture(GL_TEXTURE_CUBE_MAP, 0);
	int err = glGetError();
	if(err){
		std::cout<<"texture binding errors: "<<err<<std::endl;
	}
	ShaderManager.setMat4f("transform", this->trans);
	glDrawElements(GL_TRIANGLES, numInds, GL_UNSIGNED_INT, (void*)(EBOindex * sizeof(GLuint)));
	err = glGetError();
	if (err) {
		std::cout << "DRAWING ERRORS: ";
	}
	while(err){
		std::cout<<err<<" ";
		err = glGetError();	
	}}


