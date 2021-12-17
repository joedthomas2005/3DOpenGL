#pragma once

#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include "WindowMan.h"



class Input {
public:
	Input(Window* window, float sensitivity);
	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	static void mouse_callback(GLFWwindow* window, double x, double y);
	bool isKeyDown(unsigned int key);
	float getPitch();
	float getYaw();
	int scrWidth;
	int scrHeight;
};