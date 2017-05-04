#include "Camera.h"

//need to link this to a shader for the translations.
Camera::Camera() : speed(0.01f), sensitivity(0.005f), fly(false){
	transform_vector = glm::vec3(0, 0, 0);
	rotation_vector = -glm::vec3(-45,0,0);
	up_direction = glm::vec3(0, 1, 0);
	//camera_matrix = std::make_shared<glm::mat4>(glm::mat4());
}
Camera::~Camera(){}



std::shared_ptr<glm::mat4> Camera::getViewMatrix(){
	auto cam = glm::lookAt(transform_vector, transform_vector + rotation_vector, up_direction);
	auto camera_matrix = std::make_shared<glm::mat4>(cam);
	//std::make_shared<glm::mat4>((*rotation_matrix) * (*transform_matrix));
	return camera_matrix;
}


glm::vec3 Camera::GetCoordinates(){
	return transform_vector;
}

void Camera::Translate(glm::vec3 direction){
	transform_vector += direction * speed;
}

//rotation_matrix has to be seperate from the transform matrix as glm always rotates around the origin.
void Camera::Rotate(float x,float y){
	glm::vec3 axis = glm::vec3(0, 1, 0);
	rotation_vector = glm::rotate(rotation_vector, sensitivity * -x , axis);
	if(fly){
		axis = glm::vec3(0, 0, 1);
		rotation_vector = glm::rotate(rotation_vector, sensitivity * -y , axis);
	}
}
void Camera::UpdateCamera(Control_Key key, int x_rel, int y_rel){
  if(x_rel != 0 || y_rel != 0) Rotate(x_rel, y_rel);

	//setting all to false;
	switch(key){
		case F_KEY_D:
			ToggleFly();
			break;
    case MOVE_FORWARD_D:
      m_forward = true;
      break;
    case MOVE_BACKWARD_D:
      m_backward = true;
      break;
    case MOVE_LEFT_D:
      m_left = true;
      break;
    case MOVE_RIGHT_D:
      m_right = true;
      break;
    case MOVE_UP_D:
      m_up = true;
      break;
    case MOVE_DOWN_D:
      m_down = true;
      break;
		case MOVE_FORWARD_U:
			m_forward = false;
			break;
		case MOVE_BACKWARD_U:
			m_backward = false;
			break;
		case MOVE_LEFT_U:
			m_left = false;
			break;
		case MOVE_RIGHT_U:
			m_right = false;
			break;
		case MOVE_UP_U:
			m_up = false;
			break;
		case MOVE_DOWN_U:
			m_down = false;
			break;
		case NO_KEY:
		  m_down = false; m_up = false;
			m_left = false; m_right = false;
			m_forward = false; m_backward = false;
			break;
		}
		//after setting a value to true then move
		if(m_forward) GoForwards();
		if(m_backward) GoBackwards();
		if(m_left) GoLeft();
		if(m_right) GoRight();
		if(m_up) GoUp();
		if(m_down) GoDown();
}

void Camera::GoForwards(){
	Translate(rotation_vector);
}

void Camera::GoBackwards(){
	Translate(-rotation_vector);
}

void Camera::GoLeft(){
	Translate(-glm::cross(rotation_vector, up_direction));
}

void Camera::GoRight(){
	Translate(glm::cross(rotation_vector, up_direction));
}

void Camera::GoUp(){
	if(fly)
		Translate(glm::vec3(0, 1, 0));
}

void Camera::GoDown(){
	if(fly)
		Translate(glm::vec3(0, -1, 0));
}

void Camera::ToggleFly(){
	fly = !fly;
}
