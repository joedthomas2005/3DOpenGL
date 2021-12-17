#pragma once
#include <glm/glm/glm.hpp>
#include <glm/glm/gtc/matrix_transform.hpp>
#include <glm/glm/gtc/type_ptr.hpp>

class Camera {
public:
	glm::mat4 view;
	glm::mat4 unTranslatedView();
	Camera(float x, float y, float z, float pitch, float yaw);
	void move(float x, float y, float z, bool useGlobal = false, bool yLocked = false, float yPos = 0);
	void rotate(float pitch, float yaw);
	void setPos(float x, float y, float z);
	void setRot(float pitch, float yaw);
private:
	void genVectors();
	float pitch, yaw;
	glm::vec3 camForward;
	glm::vec3 position;
	const glm::vec3 upGlobal = glm::vec3(0.0f, 1.0f, 0.0f);
};