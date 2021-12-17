#include "FPSController.h"
FPSController::FPSController(Input* input, Camera* camera, bool fly, int forwardKey, int backKey, int leftKey, int rightKey, float speed) {
	this->speed = speed;
	this->input = input;
	this->camera = camera;
	this->fly = fly;
	this->forwardKey = forwardKey;
	this->backKey = backKey;
	this->leftKey = leftKey;
	this->rightKey = rightKey;
}

void FPSController::checkInput(float deltaTime) {

	if (input->isKeyDown(forwardKey)) {
		camera->move(0.0f, 0.0f, 0.1f * deltaTime * speed);
	}
	if (input->isKeyDown(leftKey)) {
		camera->move(-0.1f * deltaTime * speed, 0.0f, 0.0f);
	}
	if (input->isKeyDown(backKey)) {
		camera->move(0.0f, 0.0f, -0.1f * deltaTime * speed);
	}
	if (input->isKeyDown(rightKey)) {
		camera->move(0.1f * deltaTime * speed, 0.0f, 0.0f);
	}

	camera->setRot(input->getPitch(), 90.0 + input->getYaw());
}