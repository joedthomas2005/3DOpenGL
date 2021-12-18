#include "FPSController.h"

FPSController::FPSController(Input* input, Camera* camera, bool fly, int forwardKey, int backKey, int leftKey, int rightKey, int sprintKey,float speed) {
	this->speed = speed;
	this->input = input;
	this->camera = camera;
	this->fly = fly;
	this->forwardKey = forwardKey;
	this->backKey = backKey;
	this->leftKey = leftKey;
	this->rightKey = rightKey;
	this->sprintKey = sprintKey;
}

void FPSController::checkInput(float deltaTime) {
	xVel = 0, yVel = 0, zVel = 0;

	if (input->isKeyDown(forwardKey)) {
		
		zVel = 0.1f * deltaTime * speed * (input->isKeyDown(sprintKey) + 1);
		//camera->move(0.0f, 0.0f, 0.1f * deltaTime * speed * (input->isKeyDown(sprintKey) + 1), false, !fly);
	}

	if (input->isKeyDown(leftKey)) {
		xVel = -0.1f * deltaTime * speed * (input->isKeyDown(sprintKey) + 1);
		//camera->move(-0.1f * deltaTime * speed * (input->isKeyDown(sprintKey) + 1), 0.0f, 0.0f, false, !fly);
	}

	if (input->isKeyDown(backKey)) {
		zVel = -0.1f * deltaTime * speed * (input->isKeyDown(sprintKey) + 1);
		//camera->move(0.0f, 0.0f, -0.1f * deltaTime * speed * (input->isKeyDown(sprintKey) + 1), false, !fly);
	}

	if (input->isKeyDown(rightKey)) {
		xVel = 0.1f * deltaTime * speed * (input->isKeyDown(sprintKey) + 1);
		//camera->move(0.1f * deltaTime * speed * (input->isKeyDown(sprintKey) + 1), 0.0f, 0.0f, false, !fly);
	}

	camera->move(xVel, yVel, zVel);
	camera->setRot(input->getPitch(), 90.0 + input->getYaw());
}