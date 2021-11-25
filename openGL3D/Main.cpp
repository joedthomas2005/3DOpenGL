#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<iostream>
#include<vector>
#include "WindowMan.h"
#include "Input.h"
#include "ShaderMan.h"
#include "GameObject.h"
#include "Square.h"
#include "BufferManager.h"
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
	
	BufferManager BufferMan = BufferManager(vertices, indices);

	std::cout << "Buffer Objects Created" << std::endl;


	window->setColor(1.0f, 0.0f, 0.0f, 1.0f);

	while (!window->shouldClose()) {
		glClear(GL_COLOR_BUFFER_BIT);
		if (keyboard.isKeyDown(Input::ESCAPE)) {
			glfwSetWindowShouldClose(window->getWindow(), true);
		}
		ShadingBloke.use();

		for (Square object : objects) {
			object.draw(&ShadingBloke);
		}
		window->update();
	}

	delete window;
	return 0;
}


