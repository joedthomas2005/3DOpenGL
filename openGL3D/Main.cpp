#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<iostream>
#include "WindowMan.h"

int main() {
	glfwInit();
	
	Window *window = new Window(900, 800, "3D Project", 1);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "glad loading failed" << std::endl;
	}


	window->setColor(1.0f, 0.0f, 0.0f, 1.0f);

	while (!window->shouldClose()) {
		
		window->update();
	}

	delete window;
	return 0;
}