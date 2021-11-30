#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<iostream>
#include<vector>
#include "stb_image.h"
#include "WindowMan.h"
#include "Input.h"
#include "ShaderMan.h"
#include "GameObject.h"
#include "Square.h"
#include "Circle.h"
#include "Triangle.h"
#include "BufferManager.h"

int main() {
	
	glfwInit();
	
	Window *window = new Window(900, 800, "3D Project", 1);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "glad loading failed" << std::endl;
	}

	Input keyboard = Input(window->getWindow());

	ShaderMan ShadingBloke = ShaderMan("shader.vert", "shader.frag");
	
	std::cout << "Loaded window and shader" << std::endl;

	std::vector<GameObject*> objects;
	std::vector<GLuint> indices;
	std::vector<GLfloat> vertices;

	objects.push_back(new Circle(0.6f, 360, -0.5f, 0, 0, 1.0f, 1.0f, 1.0f, &vertices, &indices, "wall.jpg"));
	objects.push_back(new Circle(0.3f, 360, 0, 0, 0, 1.0f, 1.0f, 1.0f, &vertices, &indices, "wall.jpg"));
	objects.push_back(new Circle(0.1f, 360, 0.5f, 0, 0, 1.0f, 1.0f, 1.0f, &vertices, &indices, "wall.jpg"));
	objects.push_back(new Triangle(-0.1f, -0.8f, 0, 0, -0.7f, 0, 0.1f, -0.8f, 0, 1.0f, 0.0f, 0.0f, &vertices, &indices, "wall.jpg"));

	BufferManager BufferMan = BufferManager(vertices, indices);

	std::cout << "Buffer Objects Created" << std::endl;

	window->setColor(0.0f, 0.0f, 0.0f, 1.0f);
	std::cout << "Vertices: " << std::endl;
	for (GLfloat i : vertices) {
		std::cout << i << ", ";
	}

	std::cout << std::endl << "Indices" << std::endl;
	for (GLuint i : indices) {
		std::cout << i << ", ";
	}
	while (!window->shouldClose()) {
		//glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		glClear(GL_COLOR_BUFFER_BIT);

		if (keyboard.isKeyDown(Input::ESCAPE)) {
			glfwSetWindowShouldClose(window->getWindow(), true);
		}
		ShadingBloke.use();

		for (GameObject* object : objects) {
			object->draw(&ShadingBloke);
		}
		window->update();
	}

	delete window;
	return 0;
}


