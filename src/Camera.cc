#include "Camera.h"

//need to link this to a shader for the translations.
Camera::Camera() : speed(0.2f), sensitivity(0.02f){
	rotation_matrix = std::make_shared<glm::mat4>(glm::mat4());
	transform_matrix = std::make_shared<glm::mat4>(glm::mat4());
	//camera_matrix = std::make_shared<glm::mat4>(glm::mat4());
}
Camera::~Camera(){}



std::shared_ptr<glm::mat4> Camera::getViewMatrix(){
	auto camera_matrix = std::make_shared<glm::mat4>((*rotation_matrix) * (*transform_matrix));
	return camera_matrix;
}

void Camera::Translate(float x, float y, float z){
	transform_matrix = std::make_shared<glm::mat4>((*transform_matrix) * glm::translate(glm::mat4(1.0f), glm::vec3(x,y,z)));
}

//rotation_matrix has to be seperate from the transform matrix as glm always rotates around the origin.
void Camera::Rotate(float x,float y){
	rotation_matrix = std::make_shared<glm::mat4>((*rotation_matrix) * glm::rotate(glm::mat4(1.0f), sensitivity, glm::vec3(y,x,0.0f)));
}

void Camera::UpdateCamera(Control_Key key, int x_rel, int y_rel){
  if(x_rel != 0 || y_rel != 0) Rotate(x_rel, y_rel);
	//setting all to false;
	switch(key){
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
	Translate(0,0,speed);
}

void Camera::GoBackwards(){
	Translate(0,0,-speed);
}

void Camera::GoLeft(){
	Translate(speed,0,0);
}

void Camera::GoRight(){
	Translate(-speed,0,0);
}

void Camera::GoUp(){
	Translate(0,-speed,0);
}

void Camera::GoDown(){
	Translate(0,speed,0);
}
