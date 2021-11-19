#pragma once
#include<GLFW/glfw3.h>
#include<glad/glad.h>

bool keys[6] = { false };

class Input {
public:
	enum KeyCode {
		RIGHT = 0,
		LEFT = 1, 
		UP = 2,
		DOWN = 3,
		SPACE = 4,
		ESCAPE = 5
	};
	Input(GLFWwindow* window);
	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	bool isKeyDown(KeyCode key);

};