#ifndef GAMEWORLD_H
#define GAMEWORLD_H

#include <memory>

#include <GL/gl.h>

#include <fstream>
#include <iostream>
#include <string>

#include "common.h"
#include "GameAssetManager.h"
#include "GameAsset.h"
#include "CubeAsset.h"

/**
 * GameWorld allows us to separate the management of the game world from the
 * nuts and bolts of game loop initialisation.  The GameWorld currently has
 * a very simplified scene graph consisiting of a single GameAssetManager.
 */
class GameWorld {
 public:
  /**
   * We thread the ApplicationMode through the GameWorld ss we want to read it
   * in from the user.  Threading the state through the various function calls
   * is preferable (in this case) to having some kind of global state.
   */
  GameWorld(ApplicationMode);

  void CreateWorld();
  void translateCamera();
  void CheckToken(char token, uint x, uint y, uint z);
  void UpdateCamera(Control_Key c, int x_rel, int y_rel);
  bool CheckCollision(GameAsset &a, GameAsset &b);
  bool CheckCollision(glm::vec3 &a, glm::vec3 &b);

  void Update();

  /**
   * Calling Draw() will draw the entire world.
   */
  void Draw();
 private:
  std::shared_ptr<GameAssetManager> asset_manager;

  std::vector<std::shared_ptr<GameAsset>> world;
  std::vector<std::shared_ptr<GameAsset>> baddies;
  std::vector<std::shared_ptr<GameAsset>> bullets;

};
#endif // GAMEWORLD_H
