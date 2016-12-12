#pragma once
#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4


class Camera{
	public:
		Camera();
		~Camera();
		glm::mat4 getViewMatrix();
};
