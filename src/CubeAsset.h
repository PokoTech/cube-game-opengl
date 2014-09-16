#ifndef CUBEASSET_H
#define CUBEASSET_H

#include <GL/gl.h>

#include "GameAsset.h"

class CubeAsset : public GameAsset {
 public:
  CubeAsset();
  ~CubeAsset();
  virtual void Draw(GLuint);
 private:
  GLfloat * vertex_buffer;
  GLuint * element_buffer;
  GLuint element_buffer_length;
  GLuint vertex_buffer_token, element_buffer_token;
};

#endif // CUBEASSET_H
