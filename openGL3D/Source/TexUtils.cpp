#include "TexUtils.h"

void TexUtils::setFlip(bool flip) {
	stbi_set_flip_vertically_on_load(flip);
}

unsigned char* TexUtils::loadImage(std::string texPath, int* texWidth, int* texHeight, int* numChannels){
	return stbi_load(texPath.c_str(), texWidth, texHeight, numChannels, 0);
};


GLenum TexUtils::colourSpace(std::string texPath){
	std::ifstream imageSignature(texPath.c_str(), std::ios::in | std::ios::binary);
	std::cout<<"Loading image "<<texPath<<std::endl;
	char signature[128];
	imageSignature.read(signature, 128);
		
	unsigned int hexsignature[128];
		
	for(int i = 0; i < 128; i++){
		hexsignature[i] = (unsigned int)(unsigned char)(signature[i]);
	}

	if(hexsignature[0] == 0x89 && hexsignature[1] == 0x50 && hexsignature[2] == 0x4e && hexsignature[3] == 0x47){
		return GL_RGBA;
	}
	else if(hexsignature[0] == 0xff && hexsignature[1] == 0xd8){
		std::cout << "LOADING JPG" << std::endl;
		return GL_RGB;
	}
	else{
		std::cout<<"ERROR UNRECOGNISED IMAGE FORMAT, MUST BE JPG OR PNG" << std::endl;
		return 0;
	}

};

void TexUtils::freeTexData(unsigned char* texData){
	stbi_image_free(texData);
}
