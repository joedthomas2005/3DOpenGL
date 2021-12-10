#include "Input.h"
bool keys[GLFW_KEY_LAST] = { false };
Input::Input(GLFWwindow* window) {
	glfwSetKeyCallback(window, this->key_callback);
};

void Input::key_callback(GLFWwindow*, int key, int scancode, int action, int mods) {
	keys[key] = action == GLFW_PRESS ? true : action == GLFW_RELEASE ? false : keys[key];
};

bool Input::isKeyDown(unsigned int key) {
	return keys[key];
}