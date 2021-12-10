#pragma once

#include<glad/glad.h>
#include<GLFW/glfw3.h>

class Input {
public:

	Input(GLFWwindow* window);
	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	bool isKeyDown(unsigned int key);
private:
	//bool* keys;
};