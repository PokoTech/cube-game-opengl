#ifndef CUBEASSET_H
#define CUBEASSET_H

#include <vector>

#include <GL/gl.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>

#include "GameAsset.h"
#include "ModelLoader.h"

class CubeAsset : public GameAsset {
 public:
  CubeAsset();
  CubeAsset(const char* path);
  ~CubeAsset();
  virtual void Draw(GLuint);

 private:
  GLuint vertex_buffer_length, element_buffer_length;
  GLuint vertex_buffer_token, element_buffer_token;

  GLuint normal_buffer_length, normal_element_buffer_length;
  GLuint normal_buffer_token, normal_element_buffer_token;
};

#endif // CUBEASSET_H
