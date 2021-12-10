#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<glm/glm/glm.hpp>
#include<glm/glm/gtc/matrix_transform.hpp>
#include<glm/glm/gtc/type_ptr.hpp>
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

	Window *window = new Window(1800,1600, "3D Project", 1);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "glad loading failed" << std::endl;
	}

	Input keyboard = Input(window->getWindow());

	ShaderMan Shader = ShaderMan("shader.vert", "shader.frag");
	
	std::cout << "Loaded window and shader" << std::endl;

	std::vector<GameObject*> objects;
	std::vector<GLuint> indices;
	std::vector<GLfloat> vertices;

	objects.push_back(new Square(1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f,0.0f,0.0f, 1.0f, 1.0f, 1.0f, &vertices, &indices, "wall.jpg"));
	
	BufferManager BufferMan = BufferManager(vertices, indices);

	std::cout << "Buffer Objects Created" << std::endl;

	window->setColor(0.0f, 0.0f, 0.0f, 1.0f);
	


	while (!window->shouldClose()) {
		//glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		glClear(GL_COLOR_BUFFER_BIT);

		if (keyboard.isKeyDown(GLFW_KEY_ESCAPE)) {
			glfwSetWindowShouldClose(window->getWindow(), true);
		}

		if (keyboard.isKeyDown(GLFW_KEY_UP)) {
			objects[0]->rotate(10.0f, 0.0f, 0.0f);
		}

		if (keyboard.isKeyDown(GLFW_KEY_DOWN)) {
			objects[0]->rotate(-10.0f, 0.0f, 0.0f);
		}

		if (keyboard.isKeyDown(GLFW_KEY_RIGHT)) {
			objects[0]->rotate(0.0f, 10.0f, 0.0f);
		}

		if (keyboard.isKeyDown(GLFW_KEY_LEFT)) {
			objects[0]->rotate(0.0f, -10.0f, 0.0f);
		}
		Shader.use();

		for (GameObject* object : objects) {
			object->draw(&Shader);
		}

		window->update();
	}

	delete window;
	return 0;
}


