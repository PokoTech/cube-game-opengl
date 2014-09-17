#include "GameWorld.h"

GameWorld::GameWorld () {
  asset_manager = std::make_shared<GameAssetManager>();
  asset_manager->AddAsset(std::make_shared<CubeAsset>());
}

void GameWorld::Draw() {
  asset_manager->Draw();
}
