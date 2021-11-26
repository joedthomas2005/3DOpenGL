#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<iostream>
#include<vector>
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
	
	Window *window = new Window(1800, 1600, "3D Project", 1);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "glad loading failed" << std::endl;
	}

	Input keyboard = Input(window->getWindow());

	ShaderMan ShadingBloke = ShaderMan("shader.vert", "shader.frag");
	
	std::cout << "Loaded window and shader" << std::endl;

	std::vector<GameObject*> objects;
	std::vector<GLuint> indices;
	std::vector<GLfloat> vertices;

	Circle* player = new Circle(0.2f, 36, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, &vertices, &indices);

	objects.push_back(player);

	objects.push_back(new Circle(0.3f, 36, 0.0f, 0.5f, 0.0f, 0.0f, 1.0f, 0.0f, &vertices, &indices));
	objects.push_back(new Circle(0.1f, 40, -0.6f, -0.2f, 0.0f, 0.0f, 0.0f, 1.0f, &vertices, &indices));
	objects.push_back(new Square(0.3, 0.1f, -0.2f, 0.05f, 0, 1.0f, 1.0f, 1.0f, &vertices, &indices));
	objects.push_back(new Triangle(-0.3, -0.2, 0, 0.0, 0.3, 0, 0.3, -0.2, 0, 0.5f, 0.2f, 0.6f, &vertices, &indices));

	BufferManager BufferMan = BufferManager(vertices, indices);

	std::cout << "Buffer Objects Created" << std::endl;

	window->setColor(0.0f, 0.0f, 0.0f, 1.0f);

	while (!window->shouldClose()) {

		glClear(GL_COLOR_BUFFER_BIT);

		if (keyboard.isKeyDown(Input::ESCAPE)) {
			glfwSetWindowShouldClose(window->getWindow(), true);
		}

		if (keyboard.isKeyDown(Input::RIGHT)) {
			player->move(0.1f, 0, 0);
		}
		if (keyboard.isKeyDown(Input::LEFT)) {
			player->move(-0.1f, 0, 0);
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


