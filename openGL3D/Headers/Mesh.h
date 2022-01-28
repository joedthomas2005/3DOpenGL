#pragma once
#include<glad/glad.h>
#include<GLFW/glfw3.h>

#include<vector>
#include<algorithm>
#include<string>

#include "ShaderMan.h"
namespace Mesh {
	struct Texture {
		unsigned int id;
		std::string type;
	};

	class Mesh {

	public:
		Mesh(std::vector<GLfloat>& vertices, std::vector<GLuint>& indices, std::vector<Texture>& textures, std::vector<GLfloat>& VBO, std::vector<GLuint>& EBO);
		void Draw(ShaderMan& shader);
		std::vector<GLfloat> vertices;
		std::vector<GLuint> indices;
		std::vector<Texture> textures;

	private:
		int numInds;
		int EBOindex;
	};

}