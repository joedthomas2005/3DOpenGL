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
#include "GameObject2D.h"
#include "Square.h"
#include "Circle.h"
#include "Triangle.h"
#include "Cube.h"
#include "BufferManager.h"

int main() {

	glfwInit();
	
	Window *window = new Window(1800,1600, "3D Project", 1, true);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "glad loading failed" << std::endl;
	}

	glEnable(GL_DEPTH_TEST);

	Input keyboard = Input(window->getWindow());

	ShaderMan Shader = ShaderMan("shader.vert", "shader.frag", window);
	
	std::cout << "Loaded window and shader" << std::endl;

	std::vector<GameObject*> objects;
	std::vector<GLuint> indices;
	std::vector<GLfloat> vertices;

	std::vector<const char*> cubeTextures = { "wall.jpg", "wall.jpg", "wall.jpg", "wall.jpg", "wall.jpg", "wall.jpg" };
	
	
	objects.push_back(new Cube(0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, &vertices, &indices, cubeTextures));
	//objects.push_back(new Circle(36, 0.5f, 0.5f, 0.5f, 0.5f, 0.0f, 0, 0, 0, 1.0f, 1.0f, 1.0f, &vertices, &indices, "compass.png", true));
	
	BufferManager BufferMan = BufferManager(vertices, indices);

	std::cout << "Buffer Objects Created" << std::endl;

	window->setColor(1.0f, 1.0f, 1.0f, 1.0f);
	

	BufferMan.Bind();

	while (!window->shouldClose()) {
		//glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		
		if (keyboard.isKeyDown(GLFW_KEY_ESCAPE)) {
			glfwSetWindowShouldClose(window->getWindow(), true);
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


