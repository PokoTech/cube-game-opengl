#pragma once
#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp>


class Camera{
	public:
		Camera();
		~Camera();
		glm::mat4 getViewMatrix();
		void Translate(float x, float y, float z);
		void Rotate(float x, float y);
	private:
		glm::mat4 camera_matrix;
		void GoUp();
		void GoDown();
		void GoLeft();
		void GoRight();
		void GoForwards();
		void GoBackwards();
		float speed;
 		
};



