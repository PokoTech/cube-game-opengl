#ifndef GAMEASSET_H
#define GAMEASSET_H

#include <iostream>

#include <GL/gl.h>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4

class GameAsset {
 public:
	virtual ~GameAsset(){};
	virtual void Draw(GLuint) = 0;

	//places values in a mat4 matrix to be sent to the shader
	void translate(float x, float y, float z){
		matrix = glm::translate(matrix, glm::vec3(x, y, z));
	}

  // same as above but with vector input
  void translate(glm::vec3 &direction){
    matrix = glm::translate(matrix, direction);
  }

  // translates using the dir saved in the object
  void translateInDir(){
    matrix = glm::translate(matrix, dir * speed);
  }

	//places values in the vec3 color to be sent to the shader
	void setColor(float r, float g, float b){
		color = glm::vec3(r, g, b);
	}

  //sets direction to an object
  void setDirection(glm::vec3 &object){
    dir = glm::normalize(object - getCoordinates());
  }

  // returns direction of movement
  glm::vec3 getDirection(){
    return dir;
  }
  //r Returns x,y,z coordinates as a vec3
  glm::vec3 getCoordinates(){
    return glm::vec3(matrix[3][0],matrix[3][1],matrix[3][2]);
  }

  // Unused , would have returned size of object if calculated by model loader
  // glm::vec3 getSize(){
  //   return size;
  // }
 protected:
	glm::mat4 matrix = glm::mat4();
	glm::vec3 color  = glm::vec3(1.0, 0.0, 1.0);
  glm::vec3 size   = glm::vec3(0.5, 0.5, 0.5);
  glm::vec3 dir    = glm::vec3();

  float speed = 0.1;
};

#endif
