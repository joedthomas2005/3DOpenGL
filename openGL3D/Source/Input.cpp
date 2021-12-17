#include "Input.h"

namespace InputData {
	bool keys[GLFW_KEY_LAST] = { false };
	bool firstMouse = true;
	float lastX, lastY, pitch, yaw, sensitivity;
}

Input::Input(Window* window, float sensitivity) {
	InputData::sensitivity = sensitivity;
	InputData::lastX = window->getWidth() / 2;
	InputData::lastY = window->getHeight() / 2;
	glfwSetInputMode(window->getWindow(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	glfwSetKeyCallback(window->getWindow(), this->key_callback);
	glfwSetCursorPosCallback(window->getWindow(), this->mouse_callback);
};

void Input::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	InputData::keys[key] = action == GLFW_PRESS ? true : action == GLFW_RELEASE ? false : InputData::keys[key];
};

bool Input::isKeyDown(unsigned int key) {
	return InputData::keys[key];
}

void Input::mouse_callback(GLFWwindow* window, double x, double y) {
	if (InputData::firstMouse) {
		InputData::lastX = x;
		InputData::lastY = y;
		InputData::firstMouse = false;
	}
	float xoffset = InputData::sensitivity * (x - InputData::lastX);
	float yoffset = InputData::sensitivity * (InputData::lastY - y);
	InputData::lastX = x;
	InputData::lastY = y;
	InputData::yaw += xoffset;
	InputData::pitch += yoffset;
	std::cout << "yaw: " << InputData::yaw << std::endl;
	std::cout << "pitch: " << InputData::pitch << std::endl;
	if (InputData::pitch > 89.0f) {
		InputData::pitch = 89.0f;
	}
	else if (InputData::pitch < -89.0f) {
		InputData::pitch = -89.0f;
	}
}

float Input::getPitch() {
	return InputData::pitch;
}

float Input::getYaw() {
	return InputData::yaw;
}