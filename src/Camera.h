#pragma once
#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/rotate_vector.hpp>
#include <iostream>
#include <memory>


#include "common.h"


class Camera{
	public:
		Camera();
		~Camera();
		std::shared_ptr<glm::mat4> getViewMatrix();
		void Translate(glm::vec3 direction);
		void Rotate(float x, float y);
		void UpdateCamera(Control_Key key, int x_rel, int y_rel);
		glm::vec3 GetCoordinates();
	private:
		//movement methods
		void GoUp();
		void GoDown();
		void GoLeft();
		void GoRight();
		void GoForwards();
		void GoBackwards();
		void ToggleFly();

		glm::vec3 rotation_vector;
		glm::vec3 transform_vector;
		glm::vec3 up_direction;

		float speed;
		float sensitivity;
		bool fly;

		//movement booleans
		bool m_forward = false, m_backward = false, m_left = false,
		 		 m_right = false, m_up = false, m_down = false;
};
