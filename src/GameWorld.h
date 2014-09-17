#ifndef GAMEWORLD_H
#define GAMEWORLD_H

#include <memory>

#include <GL/gl.h>

#include "GameAssetManager.h"
#include "CubeAsset.h"

class GameWorld {
 public:
  GameWorld();
 private:
  std::shared_ptr<GameAssetManager> asset_manager;
};
#endif // GAMEWORLD_H
