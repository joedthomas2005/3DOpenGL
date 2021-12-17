#include "Camera.h"

Camera::Camera(float x, float y, float z, float pitch, float yaw) {
	this->position = glm::vec3(x, y, z);
	this->camForward = glm::vec3(0.0f, 0.0f, -1.0f);
	this->pitch = pitch;
	this->yaw = yaw;
	this->genVectors();

}

void Camera::genVectors() {

	float xFacing = cos(glm::radians(this->yaw)) * cos(glm::radians(this->pitch));
	float yFacing = sin(glm::radians(this->pitch));
	float zFacing = sin(glm::radians(this->yaw)) * cos(glm::radians(this->pitch));
	this->camForward = glm::normalize(glm::vec3(xFacing, yFacing, zFacing));
	this->view = glm::lookAt(position, position + camForward, upGlobal);

}

void Camera::move(float x, float y, float z, bool useGlobal, bool yLocked, float yPos) {
	if (useGlobal) {
		this->position.x += x;
		this->position.y += y;
		this->position.z += z;
	}
	else {
		this->position += z * camForward;	//z axis = forward therefore use the facing vector
		this->position += x * glm::normalize(glm::cross(camForward, upGlobal));			//vector cross product produces normal to face containing both others, therefore cross of z and y produces x 
		this->position += y * upGlobal;		//same as position.y += y as upGlobal is (0,1,0)
	}

	if (yLocked) {
		this->position.y = yPos;
	}
	genVectors();
}

void Camera::rotate(float pitch, float yaw) {
	this->pitch += pitch;
	this->yaw += yaw;
	genVectors();
}

void Camera::setPos(float x, float y, float z) {
	this->position = glm::vec3(x, y, z);
}
void Camera::setRot(float pitch, float yaw) {
	this->pitch = pitch;
	this->yaw = yaw;
	genVectors();
}

glm::mat4 Camera::unTranslatedView() {
	return glm::mat4(glm::mat3(view));
}