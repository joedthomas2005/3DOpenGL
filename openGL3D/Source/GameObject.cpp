#include "GameObject.h"

void GameObject::move(float x, float y, float z){
	this->x += x;
	this->y += y;
	this->z += z;
};

void GameObject::rotate(float pitch, float yaw, float roll){
	this->pitch -= pitch;
	this->yaw += yaw;
	this->roll -= roll;
};

void GameObject::scale(float x, float y, float z){
	this->xScale += x;
	this->yScale += y;
	this->zScale += z;
};

GameObject::GameObject(float x, float y, float z, float pitch, float yaw, float roll, float xscale, float yscale, float zscale, bool UI){
	this->UI = UI;
	this->x = x;
	this->y = y;
	this->z = z;
	this->pitch = pitch;
	this->yaw = yaw;
	this->roll = roll;
	this->xScale = xscale;
	this->yScale = yscale;
	this->zScale = zscale;
};

void GameObject::genTransformMatrix(){
	this->trans = glm::mat4(1.0f);
	this->trans = glm::translate(this->trans, glm::vec3(x,y,z));
	this->trans = glm::rotate(this->trans, glm::radians(pitch), glm::vec3(1.0f,0.0f,0.0f));
	this->trans = glm::rotate(this->trans, glm::radians(yaw), glm::vec3(0.0f,1.0f,0.0f));
	this->trans = glm::rotate(this->trans, glm::radians(roll), glm::vec3(0.0f,0.0f,1.0f));
	this->trans = glm::scale(this->trans, glm::vec3(xScale, yScale, zScale));
};
