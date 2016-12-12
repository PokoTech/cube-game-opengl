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
	void translate(float x, float y, float z){
		matrix *= glm::translate(glm::mat4(1.0f), glm::vec3(x, y, z));
	}
 protected:
	glm::mat4 matrix = glm::mat4();
};

#endif
