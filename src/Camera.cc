#include "Camera.h"

//need to link this to a shader for the translations.
Camera::Camera() : speed(30.0f), sensitivity(50.0f){
	camera_matrix = glm::mat4();
}
Camera::~Camera(){}


glm::mat4 Camera::getViewMatrix(){
	return camera_matrix;
}
//setup camera_matrix transformations
void Camera::Translate(float x, float y, float z){
	camera_matrix *= glm::translate(glm::mat4(1.0f), glm::vec3(x,y,z));
}

void Camera::Rotate(float x,float y){
	camera_matrix += glm::rotate(glm::mat4(1.0f), sensitivity, glm::vec3(y,x,0.0f));
}
//updates the camera in real time if case equals true move in direction.
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
//translates the camera_matrix to move in the different directions with a set speed
void Camera::GoForwards(){
	camera_matrix += glm::translate(glm::mat4(1.0f), glm::vec3(0.0f,0.0f,speed));
}

void Camera::GoBackwards(){
	camera_matrix += glm::translate(glm::mat4(1.0f), glm::vec3(0.0f,0.0f,-speed));
}

void Camera::GoLeft(){
	camera_matrix += glm::translate(glm::mat4(1.0f), glm::vec3(-speed,0.0f,0.0f));
}

void Camera::GoRight(){
	camera_matrix += glm::translate(glm::mat4(1.0f), glm::vec3(speed,0.0f,0.0f));
}

void Camera::GoUp(){
	camera_matrix += glm::translate(glm::mat4(1.0f), glm::vec3(0.0f,speed,0.0f));
}

void Camera::GoDown(){
	camera_matrix += glm::translate(glm::mat4(1.0f), glm::vec3(0.0f,-speed,0.0f));
}
