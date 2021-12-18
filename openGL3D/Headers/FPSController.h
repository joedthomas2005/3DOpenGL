#pragma once
#include "Input.h"
#include "Camera.h"

class FPSController {
public:
	FPSController(Input* input, Camera* camera, bool fly, int forwardKey, int backKey, int rightKey, int leftKey, int sprintKey, float speed);
	void checkInput(float deltaTime);
private:
	float x, y, z, yVel, xVel, zVel;
	int forwardKey, backKey, rightKey, leftKey, sprintKey;
	float speed;
	bool fly;
	bool firstFrame;
	Input* input;
	Camera* camera;
};