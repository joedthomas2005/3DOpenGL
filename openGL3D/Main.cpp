#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<iostream>
#include "WindowMan.h"
#include "Input.h"
int main() {
	bool keys[6] = { false };
	glfwInit();
	
	Window *window = new Window(900, 800, "3D Project", 1);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "glad loading failed" << std::endl;
	}

	Input keyboard = Input(window->getWindow(), keys);

	window->setColor(1.0f, 0.0f, 0.0f, 1.0f);

	while (!window->shouldClose()) {
		if (keyboard.isKeyDown(Input::ESCAPE)) {
			glfwSetWindowShouldClose(window->getWindow(), true);
		}

		window->update();
	}

	delete window;
	return 0;
}