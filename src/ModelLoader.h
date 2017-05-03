#ifndef MODELLOADER_H
#define MODELLOADER_H
/**
 * A very wobbly implementation of a custome model loader.
 * ModelLoader loads in simple objects from .obj files and returns a
 * vertex_buffer and element_buffer to use for rendering.
 */

 #include <fstream>
 #include <iostream>
 #include <string>
 #include <vector>

 #include <GL/gl.h>


 class ModelLoader{
  public:
    static bool loadObject(const char* path,
                           std::vector<GLfloat> &out_vertex_buffer,
                           std::vector<GLuint>  &out_element_buffer,
                           std::vector<GLfloat> &out_normal_buffer );
 };


#endif
