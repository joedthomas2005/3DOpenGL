#include "Input.h"
bool keys[6] = { false };
Input::Input(GLFWwindow* window) {
	glfwSetKeyCallback(window, this->key_callback);
};

void Input::key_callback(GLFWwindow*, int key, int scancode, int action, int mods) {
	switch (key) {
	case GLFW_KEY_RIGHT:
		keys[RIGHT] = action == GLFW_PRESS ? true : action == GLFW_RELEASE ? false : keys[RIGHT];
		break;
	case GLFW_KEY_LEFT:
		keys[LEFT] = action == GLFW_PRESS ? true : action == GLFW_RELEASE ? false : keys[LEFT];
		break;
	case GLFW_KEY_UP:
		keys[UP] = action == GLFW_PRESS ? true : action == GLFW_RELEASE ? false : keys[UP];
		break;
	case GLFW_KEY_DOWN:
		keys[DOWN] = action == GLFW_PRESS ? true : action == GLFW_RELEASE ? false : keys[DOWN];
		break;
	case GLFW_KEY_SPACE:
		keys[SPACE] = action == GLFW_PRESS ? true : action == GLFW_RELEASE ? false : keys[SPACE];
		break;
	case GLFW_KEY_ESCAPE:
		keys[ESCAPE] = action = GLFW_PRESS ? true : action == GLFW_RELEASE ? false : keys[ESCAPE];
		break;
	};
};

bool Input::isKeyDown(Input::KeyCode key) {
	return keys[key];
}