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
#include "Camera.h"
#include "FPSController.h"

int main() {

	glfwInit();
	
	Window *window = new Window(900,800, "3D Project", 1, false);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "glad loading failed" << std::endl;
	}

	glEnable(GL_DEPTH_TEST);
	
	ShaderMan Shader = ShaderMan("shader.vert", "shader.frag", window);
	
	std::cout << "Loaded window and shader" << std::endl;

	std::vector<GameObject*> objects;


	std::vector<GLuint> indices;
	std::vector<GLfloat> vertices;
	std::vector<const char*> skyboxTextures = { "skybox/right.jpg", "skybox/left.jpg", "skybox/top.jpg", "skybox/bottom.jpg", "skybox/front.jpg", "skybox/back.jpg" };

	Cube skybox = Cube(0, 0, 0, 1.0f, 1.0f, 1.0f, 0, 0, 0, 1.0f, 1.0f, 1.0f, vertices, indices, skyboxTextures);

	objects.push_back(new Cube(0.0f, 0.0f, 0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, vertices, indices, "grassblock.jfif"));
	


	BufferManager BufferMan = BufferManager(vertices, indices);

	Input input = Input(window, 0.1f);
	Camera camera = Camera(0, 0, 0, 0, 0);

	FPSController camController = FPSController(&input, &camera, true, GLFW_KEY_W, GLFW_KEY_S, GLFW_KEY_A, GLFW_KEY_D, GLFW_KEY_LEFT_SHIFT,5.0f);

	std::cout << "Buffer Objects Created" << std::endl;

	window->setColor(1.0f, 1.0f, 1.0f, 1.0f);
	

	double deltaTime = 0;
	double currentFrame = 0;
	double lastFrame = 0;
	
	while (!window->shouldClose()) {
		glGetError();
		//calculate frame time
		currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;

		std::cout << "FPS: " << 1.0f / deltaTime << "\n";

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		if (input.isKeyDown(GLFW_KEY_ESCAPE)) {
			glfwSetWindowShouldClose(window->getWindow(), true);
		}
		camController.checkInput(deltaTime);

		glDepthMask(GL_FALSE);
		Shader.use(camera.unTranslatedView());
		skybox.draw(Shader);
		//std::cout << "ERROR WHILE DRAWING SHADERS? " << glGetError() << std::endl;
		glDepthMask(GL_TRUE);
		Shader.use(camera.view);
		
		for (GameObject *object : objects) {
			object->draw(Shader);
		}

		window->update();
	}
	delete window;

	char a;
	std::cin >> a;
	return 0;
}


