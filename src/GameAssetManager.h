#ifndef GAMEASSETMANAGER_H
#define GAMEASSETMANAGER_H

#include <memory>
#include <vector>
#include <string>
#include <utility>
#include <fstream>
#include <iostream>

#define GL3_PROTOTYPES 1 // Ensure OpenGl 3 core only.
#include <GL/gl.h>

#include "GameAsset.h"

class GameAssetManager {
 public:
  GameAssetManager& getInstance();
  void addAsset(std::shared_ptr<GameAsset>);

 private:
  GameAssetManager(); // constructor
  GameAssetManager(GameAssetManager const&); // copy constructor
  GameAssetManager(GameAssetManager const&&); // move constructor
  void operator=(GameAssetManager const&); // assignment

  GLuint CreateGLProgram(std::string &, std::string &);
  GLuint CreateGLESShader(GLenum, std::string &);
  // As this is private and we're writing to the GPU, we will use raw pointers.
  std::pair<GLchar *, GLint>  ReadShader(std::string &);

  static std::vector<std::shared_ptr<GameAsset>> draw_list;
  GLuint program;
};

#endif // GAMEASSETMANAGER_H
