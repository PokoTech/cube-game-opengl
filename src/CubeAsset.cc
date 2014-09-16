#include "CubeAsset.h"

CubeAsset::CubeAsset() {
  // model coordinates, origin at centre.
  vertex_buffer = new GLfloat[12]{
    -0.5, -0.5, -0.5
    , -0.5,  0.5, -0.5
    ,  0.5, -0.5, -0.5
    ,  0.5,  0.5, -0.5
  };

  element_buffer_length = 6;
  element_buffer = new GLuint[element_buffer_length]{
    0, 1, 2
    , 1, 3, 2
  };
}

CubeAsset::~CubeAsset() {
  delete(vertex_buffer);
  delete(element_buffer);
}

void CubeAsset::Draw(GLuint program_token) {
  GLuint position_attrib = glGetAttribLocation(program_token, "position");
  glUseProgram(program_token);

  glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer_token);
  glVertexAttribPointer(
                        position_attrib,               /* attribute */
                        3,                             /* size */
                        GL_FLOAT,                      /* type */
                        GL_FALSE,                      /* normalized? */
                        0,                             /* stride */
                        (void*)0                       /* array buffer offset */
                        );
  glEnableVertexAttribArray(position_attrib);

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, element_buffer_token);
  glDrawElements(
                 GL_TRIANGLES,
                 element_buffer_length,
                 GL_UNSIGNED_SHORT,
                 (GLvoid*) 0
                 );

  glDisableVertexAttribArray(position_attrib);
}
