#pragma once

#include<glad/glad.h>
#include<GLFW/glfw3.h>

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
	Input(GLFWwindow* window, bool* KeyArray);
	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	bool isKeyDown(KeyCode key);
private:
	//bool* keys;
};