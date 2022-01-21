#pragma once
#include<glad/glad.h>
#include<GLFW/glfw3.h>

#include<vector>
#include<algorithm>
#include<string>
namespace Mesh {
	struct Texture {
		unsigned int id;
		std::string type;
	};

	class Mesh {
	public:
		std::vector<GLfloat> vertices;
		std::vector<GLuint> indices;
		std::vector<Texture> textures;


	};

}