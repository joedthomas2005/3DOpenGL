#pragma once
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<iostream>
class Window {
private: 
	GLFWwindow* window;
	int *pWidth;
	int *pHeight;

	static void callbackError(int error, const char* description);
	static void frameBufferSizeCallback(GLFWwindow* window, int width, int height);
public:
	Window(int width, int height, const char* title, int swap_interval);
	void initViewport();
	void setSwapInterval(int interval);
	bool shouldClose();
	void setColor(float r, float g, float b, float a);
	GLFWwindow* getWindow();
	void update();
	~Window();
};