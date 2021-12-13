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
	
	Window *window = new Window(900,800, "3D Project", 1);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "glad loading failed" << std::endl;
	}

	glEnable(GL_DEPTH_TEST);

	Input keyboard = Input(window->getWindow());

	ShaderMan Shader = ShaderMan("shader.vert", "shader.frag");
	
	std::cout << "Loaded window and shader" << std::endl;

	std::vector<GameObject*> UIobjects;
	std::vector<GLuint> UIindices;
	std::vector<GLfloat> UIvertices;


	std::vector<Cube*> Cubes;


	UIobjects.push_back(new Circle(36, 0.4f, 0.4f, 0.8f, 0.7f, 1.0f, 0, 0, 0, 1.0f, 1.0f, 1.0f, &UIvertices, &UIindices, "compass.png"));

	BufferManager UIBufferMan = BufferManager(UIvertices, UIindices);

	std::cout << "Buffer Objects Created" << std::endl;

	window->setColor(1.0f, 1.0f, 1.0f, 1.0f);
	

	UIBufferMan.Bind();

	while (!window->shouldClose()) {
		//glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		if (keyboard.isKeyDown(GLFW_KEY_ESCAPE)) {
			glfwSetWindowShouldClose(window->getWindow(), true);
		}
		Shader.use();

		
		for (GameObject* UIobject: UIobjects) {
			UIobject->draw(&Shader);
		}


		window->update();
	}

	delete window;
	return 0;
}


