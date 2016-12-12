#include "GameWorld.h"

GameWorld::GameWorld (ApplicationMode mode) : asset_manager(std::make_shared<GameAssetManager>(mode)) {
	auto cube1 = std::make_shared<CubeAsset>();
	auto cube2 = std::make_shared<CubeAsset>();
	cube1->translate(2, 0, 0);
	cube2->translate(-2, 0, 0);
	asset_manager->AddAsset(cube1);
	asset_manager->AddAsset(cube2);
}

void GameWorld::Draw() {
  asset_manager->Draw();
}
