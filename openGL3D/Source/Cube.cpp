#include "Cube.h"

Cube::Cube(float x, float y, float z,
	float width, float height, float depth,
	float pitch, float yaw, float roll,
	float r, float g, float b,
	std::vector<GLfloat>& VBO, std::vector<GLuint>& EBO,
	std::vector<const char*> texturePaths) 
	:GameObject(x, y, z, pitch, yaw, roll, width, height, depth, false)
{
	std::vector<GLuint> indices = {
		6, 4, 0, 0, 2, 6,		//FRONT
		0, 1, 2, 2, 3, 1,		//RIGHT
		7, 5, 1, 1, 3, 7,		//BACK
		4, 5, 6, 6, 7, 5,		//LEFT
		4, 0, 5, 5, 1, 0,		//TOP
		6, 7, 2, 2, 3, 7		//BOTTOM
	};
	std::vector<GLfloat> verts;
	
	/**
	TOP RIGHT FRONT 0
	TOP RIGHT BACK 1
	BOTTOM RIGHT FRONT 2
	BOTTOM RIGHT BACK 3 
	TOP LEFT FRONT 4
	TOP LEFT BACK 5 
	BOTTOM LEFT FRONT 6
	BOTTOM LEFT BACK 7
	**/
	for (int w = 1; w >= -1; w -= 2) {
		for (int h = 1; h >= -1; h -= 2) {
			for (int d = 1; d >= -1; d -= 2) {
				verts.push_back(w * 0.25f);
				verts.push_back(h * 0.25f);
				verts.push_back(d * 0.25f);
				verts.push_back(r);
				verts.push_back(g);
				verts.push_back(b);
				verts.push_back(0);
				verts.push_back(0);
			}
		}
	}
	std::cout << "CUBE VERTS" << std::endl;
	for (GLfloat v : verts) {
		std::cout << v << ",";
	}
	std::cout << std::endl;
	
	this->load(verts, indices, VBO, EBO, texturePaths);
	

}

Cube::Cube(float x, float y, float z,
	float width, float height, float depth,
	float pitch, float yaw, float roll,
	float r, float g, float b,
	std::vector<GLfloat>& VBO, std::vector<GLuint>& EBO,
	const char* right, const char* left, const char* top, const char* bottom, const char* front, const char* back)
	:GameObject(x, y, z, pitch, yaw, roll, width, height, depth, false)
{
	std::vector<GLuint> indices = {
		6, 4, 0, 0, 2, 6,		//FRONT
		0, 1, 2, 2, 3, 1,		//RIGHT
		7, 5, 1, 1, 3, 7,		//BACK
		4, 5, 6, 6, 7, 5,		//LEFT
		4, 0, 5, 5, 1, 0,		//TOP
		6, 7, 2, 2, 3, 7		//BOTTOM
	};
	std::vector<GLfloat> verts;

	/**
	TOP RIGHT FRONT 0
	TOP RIGHT BACK 1
	BOTTOM RIGHT FRONT 2
	BOTTOM RIGHT BACK 3
	TOP LEFT FRONT 4
	TOP LEFT BACK 5
	BOTTOM LEFT FRONT 6
	BOTTOM LEFT BACK 7
	**/
	for (int w = 1; w >= -1; w -= 2) {
		for (int h = 1; h >= -1; h -= 2) {
			for (int d = 1; d >= -1; d -= 2) {
				verts.push_back(w * 0.25f);
				verts.push_back(h * 0.25f);
				verts.push_back(d * 0.25f);
				verts.push_back(r);
				verts.push_back(g);
				verts.push_back(b);
				verts.push_back(0);
				verts.push_back(0);
			}
		}
	}
	std::cout << "CUBE VERTS" << std::endl;
	for (GLfloat v : verts) {
		std::cout << v << ",";
	}
	std::cout << std::endl;

	this->load(verts, indices, VBO, EBO, std::vector<const char*>{right, left, top, bottom, front, back});


}

Cube::Cube(float x, float y, float z,
	float width, float height, float depth,
	float pitch, float yaw, float roll,
	float r, float g, float b,
	std::vector<GLfloat>& VBO, std::vector<GLuint>& EBO,
	const char* texturePath)
	:GameObject(x, y, z, pitch, yaw, roll, width, height, depth, false)
{
	std::vector<GLuint> indices = {
		6, 4, 0, 0, 2, 6,		//FRONT
		0, 1, 2, 2, 3, 1,		//RIGHT
		7, 5, 1, 1, 3, 7,		//BACK
		4, 5, 6, 6, 7, 5,		//LEFT
		4, 0, 5, 5, 1, 0,		//TOP
		6, 7, 2, 2, 3, 7		//BOTTOM
	};
	std::vector<GLfloat> verts;

	/**
	TOP RIGHT FRONT 0
	TOP RIGHT BACK 1
	BOTTOM RIGHT FRONT 2
	BOTTOM RIGHT BACK 3
	TOP LEFT FRONT 4
	TOP LEFT BACK 5
	BOTTOM LEFT FRONT 6
	BOTTOM LEFT BACK 7
	**/
	for (int w = 1; w >= -1; w -= 2) {
		for (int h = 1; h >= -1; h -= 2) {
			for (int d = 1; d >= -1; d -= 2) {
				verts.push_back(w * 0.25f);
				verts.push_back(h * 0.25f);
				verts.push_back(d * 0.25f);
				verts.push_back(r);
				verts.push_back(g);
				verts.push_back(b);
				verts.push_back(0);
				verts.push_back(0);
			}
		}
	}
	std::cout << "CUBE VERTS" << std::endl;
	for (GLfloat v : verts) {
		std::cout << v << ",";
	}
	std::cout << std::endl;

	this->load(verts, indices, VBO, EBO, std::vector<const char*>{texturePath, texturePath, texturePath, texturePath ,texturePath, texturePath});


}

void Cube::load(std::vector<GLfloat> &objVertices, std::vector<GLuint> &objIndices, std::vector<GLfloat> &VBOvector, std::vector<GLuint>& EBOvector, std::vector<const char*> texturePaths){
	
	std::string textureName;
	std::string completePath;

	int width, height, numChannels;
	unsigned char* data;
	
	glGenTextures(1, &(this->texture));
	glBindTexture(GL_TEXTURE_CUBE_MAP, this->texture);
	std::cout << "TEXTURE BIND CUBE ERRORS: " << glGetError() << std::endl;

	for(int i = 0; i < texturePaths.size(); i++){
		textureName = texturePaths[i];
		completePath = TEXTUREDIR + textureName;
		data = TexUtils::loadImage(completePath, &width, &height, &numChannels);
		GLenum colourSpace = TexUtils::colourSpace(completePath);
		std::cout << "On Texture " << i << std::endl;
		std::cout << "Binding Texture image" << std::endl;
		glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, colourSpace, width, height, 0, colourSpace, GL_UNSIGNED_BYTE, data);
		std::cout << "Errors: " << glGetError() << std::endl;
		TexUtils::freeTexData(data);
	}
	std::cout << "Generating Mipmap" << std::endl;
	glGenerateMipmap(GL_TEXTURE_CUBE_MAP);
	std::cout << "Errors: " << glGetError() << std::endl;

	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

	std::cout << "TEXTURE PARAMETER CUBE ERRORS: " << glGetError() << std::endl;

	VBOvector.reserve(objVertices.size());
	EBOvector.reserve(objIndices.size());

	int EBOvertexoffset;

	if(EBOvector.size() > 0){
		EBOvertexoffset = *std::max_element(EBOvector.begin(), EBOvector.end()) + 1;
	}
	else{
		EBOvertexoffset = 0;
	}

	this->EBOindex = EBOvector.size();

	for(int i = 0; i < objIndices.size(); i++){
		EBOvector.push_back(objIndices[i] + EBOvertexoffset);
	}
	
	for(int i = 0; i < objVertices.size(); i++){
		VBOvector.push_back(objVertices[i]);
	}
	this->numVerts = objVertices.size();
	this->numInds = objIndices.size();
	//std::cout << "NumVerts: " << numVerts << "\n";
	//std::cout << "NumInds: " << numInds << "\n";
	this->genTransformMatrix();
}


void Cube::draw(ShaderMan& Shader){
	glGetError();
	this->genTransformMatrix();
	Shader.setBool("isCube", true);
	Shader.setBool("isUI", false);
	glBindTexture(GL_TEXTURE_CUBE_MAP, this->texture);
	//std::cout << "Texture Binding Errors: " << glGetError() << std::endl;
	glBindTexture(GL_TEXTURE_2D, 0);
	//std::cout << "Texture Binding Errors: " << glGetError() << std::endl;
	Shader.setMat4f("transform", this->trans);
	//std::cout << "Drawing " << numInds << " indices from " << EBOindex << std::endl;
	glDrawElements(GL_TRIANGLES, numInds, GL_UNSIGNED_INT, (void*)(EBOindex * sizeof(GLuint)));
	//std::cout << "DRAWING ERRORS: " << glGetError() << std::endl;
}
