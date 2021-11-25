#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<iostream>
#include<vector>
#include "WindowMan.h"
#include "Input.h"
#include "ShaderMan.h"
#include "GameObject.h"
#include "Square.h"

int main() {
	bool keys[6] = { false };
	glfwInit();
	
	Window *window = new Window(900, 800, "3D Project", 1);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "glad loading failed" << std::endl;
	}

	Input keyboard = Input(window->getWindow(), keys);

	ShaderMan ShadingBloke = ShaderMan("shader.vert", "shader.frag");
	
	std::cout << "Loaded window and shader" << std::endl;

	std::vector<Square> objects;
	std::vector<GLuint> indices;
	std::vector<GLfloat> vertices;

	Square square = Square(0.2f, 0.2f, 0.0f, 1.0f, 0.0f, &vertices, &indices);

	std::cout << "Square Created" << std::endl;

	objects.push_back(square);
	
	unsigned int VBO, VAO, EBO;

	glGenBuffers(1, &EBO);
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	
	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * vertices.size(), vertices.data(), GL_DYNAMIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint) * indices.size(), indices.data(), GL_DYNAMIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void*)0);
	glEnableVertexAttribArray(0);
	
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void*)(sizeof(GLfloat) * 3));
	glEnableVertexAttribArray(1);

	std::cout << "Buffer Objects Created" << std::endl;
	
	
	

	std::cout << "vertices : " << std::endl;
	
	for (int i = 0; i < vertices.size(); i++) {
		std::cout << vertices[i]<<std::endl;
	}

	std::cout << "indices: " << std::endl;
	for (int i = 0; i < indices.size(); i++) {
		std::cout << indices[i] << std::endl;
	}

	window->setColor(1.0f, 0.0f, 0.0f, 1.0f);

	while (!window->shouldClose()) {
		if (keyboard.isKeyDown(Input::ESCAPE)) {
			glfwSetWindowShouldClose(window->getWindow(), true);
		}
		ShadingBloke.use();
		glBindVertexArray(VAO);
		for (Square object : objects) {
			object.draw(&ShadingBloke);
		}
		window->update();
	}

	delete window;
	return 0;
}