#pragma once
#include "Input.h"
#include "Camera.h"

class FPSController {
public:
	FPSController(Input* input, Camera* camera, bool fly, int forwardKey, int backKey, int rightKey, int leftKey, float speed);
	void checkInput(float deltaTime);
private:
	int forwardKey, backKey, rightKey, leftKey;
	float speed;
	bool fly;
	bool firstFrame;
	Input* input;
	Camera* camera;
};