#include "Camera.h"

Camera::Camera() : speed(0.1f){
	camera_matrix = glm::mat4();
}
Camera::~Camera(){}


glm::mat4 Camera::getViewMatrix(){
	return camera_matrix;
}

void Camera::Translate(float x, float y, float z){
	camera_matrix *= glm::translate(glm::mat4(1.0f), glm::vec3(x,y,z));
}

void Camera::Rotate(float x,float y){
	
}

void Camera::GoForwards(){
	camera_matrix *= glm::translate(glm::mat4(1.0f), glm::vec3(0.0f,0.0f,speed));
}

void Camera::GoBackwards(){
	camera_matrix *= glm::translate(glm::mat4(1.0f), glm::vec3(0.0f,0.0f,-speed));
}

void Camera::GoLeft(){
	camera_matrix *= glm::translate(glm::mat4(1.0f), glm::vec3(-speed,0.0f,0.0f));
}

void Camera::GoRight(){
	camera_matrix *= glm::translate(glm::mat4(1.0f), glm::vec3(speed,0.0f,0.0f));
}

void Camera::GoUp(){
	camera_matrix *= glm::translate(glm::mat4(1.0f), glm::vec3(0.0f,speed,0.0f));
}

void Camera::GoDown(){
	camera_matrix *= glm::translate(glm::mat4(1.0f), glm::vec3(0.0f,-speed,0.0f));
}


