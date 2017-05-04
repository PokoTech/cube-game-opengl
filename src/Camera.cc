#include "Camera.h"

//need to link this to a shader for the translations.
Camera::Camera(float x, float y, float z) : speed(0.002f), sensitivity(0.005f), fly(false){
	transform_vector = glm::vec3(x, y, z);
	rotation_vector = -glm::vec3(-45,0,0);
	up_direction = glm::vec3(0, 1, 0);
}
Camera::~Camera(){}


/*
 * Uses rotation and translaton vector to create a mat4 which gets sent to the shader.
 * Changed from multiplying 2 matrixes for clarity and faster performance on CPU
 */
std::shared_ptr<glm::mat4> Camera::getViewMatrix(){
	auto cam = glm::lookAt(transform_vector, transform_vector + rotation_vector, up_direction);
	auto camera_matrix = std::make_shared<glm::mat4>(cam);
	return camera_matrix;
}

/*
 * returns current position of camera
 */
glm::vec3 Camera::GetCoordinates(){
	return transform_vector;
}

/*
 * returns current rotation of camera
 */
glm::vec3 Camera::GetRotation(){
	return rotation_vector;
}

/*
 * Used for reverting to the last position when the camera hits a wall
 * this stops the camera from going through the wall in most cases.
 */
void Camera::RevertToLast(){
	transform_vector = undo_transform;
}

/*
 * Translates camera by vector 3
 */

void Camera::Translate(glm::vec3 direction){
	undo_transform = transform_vector;
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

/*
 * Contains all input checks for the camera using the SDL events from main.cc
 */
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

/*
 * Various movement abstractions
 */

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

/*
 * Press F to fly around the world.
 */

void Camera::ToggleFly(){
	fly = !fly;
}
