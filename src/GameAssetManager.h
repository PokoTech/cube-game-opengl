#ifndef GAMEASSETMANAGER_H
#define GAMEASSETMANAGER_H

#include <memory>
#include <vector>
#include <string>
#include <utility>
#include <fstream>
#include <iostream>

#include <GL/gl.h>

#include "GameAsset.h"

class GameAssetManager {
 public:
  GameAssetManager(); // constructor
  GameAssetManager(GameAssetManager const&); // copy constructor
  GameAssetManager(GameAssetManager const&&); // move constructor
  void operator=(GameAssetManager const&); // assignment
  void AddAsset(std::shared_ptr<GameAsset>);
  void Draw();

 private:
  GLuint CreateGLProgram(std::string &, std::string &);
  GLuint CreateGLESShader(GLenum, std::string &);
  // As this is private and we're writing to the GPU, we will use raw pointers.
  std::pair<GLchar *, GLint>  ReadShader(std::string &);

  std::vector<std::shared_ptr<GameAsset>> draw_list;
  GLuint program_token;
};

#endif // GAMEASSETMANAGER_H
