#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <fstream>
#include <string>
#include <iostream>
#include "stb_image.h"

namespace TexUtils{
	unsigned char* loadImage(std::string texPath, int* texWidth, int* texHeight, int* numChannels);
	GLenum colourSpace(std::string texPath);
	void freeTexData(unsigned char* texData);
	void setFlip(bool flip);
}
