#include "WindowMan.h"

void Window::callbackError(int error, const char* description) {
	std::cerr << "Window Error: " << description << std::endl;
}

void Window::frameBufferSizeCallback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}

Window::Window(int width, int height, const char* title, int vsync, bool fullScreen) {
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	WIDTH = width;
	HEIGHT = height;
	glfwSetErrorCallback(callbackError);
	GLFWmonitor* fullscreen = fullScreen ? glfwGetPrimaryMonitor() : NULL;
	window = glfwCreateWindow(width, height, title, fullscreen, NULL);
	if (window == NULL) {
		std::cerr << "GLFW FAILED LOADING WINDOW" << std::endl;
	}
	glfwMakeContextCurrent(window);
	glfwSwapInterval(vsync);
	pWidth = new int;
	pHeight = new int;
	glfwGetFramebufferSize(window, pWidth, pHeight);
	glfwSetFramebufferSizeCallback(window, frameBufferSizeCallback);
}

void Window::initViewport() {
	glViewport(0, 0, *pWidth, *pHeight);
}

void Window::setSwapInterval(int interval) {
	glfwSwapInterval(interval);
}

void Window::setColor(float r, float g, float b, float a) {
	glClearColor(r, g, b, a);
}
bool Window::shouldClose() {
	return glfwWindowShouldClose(window);
}

GLFWwindow* Window::getWindow() {
	return window;
}

void Window::update() {
	glfwSwapBuffers(window);
	glfwPollEvents();
}

Window::~Window() {
	delete pWidth;
	delete pHeight;
	glfwDestroyWindow(window);
	glfwTerminate();
}

int Window::getWidth() {
	return WIDTH;
}

int Window::getHeight() {
	return HEIGHT;
}