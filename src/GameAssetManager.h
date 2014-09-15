#ifndef GAMEASSETMANAGER_H
#define GAMEASSETMANAGER_H

#include <memory>

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

  static std::shared_ptr<GameAssetManager> gam;
};

#endif // GAMEASSETMANAGER_H
