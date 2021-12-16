#pragma once
#include <glm/glm/glm.hpp>
#include <glm/glm/gtc/matrix_transform.hpp>
#include <glm/glm/gtc/type_ptr.hpp>
#include "Input.h"

class Camera {
public:
	glm::mat4 view;
	Camera(float x, float y, float z, float pitch, float yaw, float roll);
	void update();
private:
	float x, y, z, pitch, yaw, roll;
};