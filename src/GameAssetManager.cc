#include "GameAssetManager.h"

GameAssetManager& GameAssetManager::getInstance() {
  static GameAssetManager the_manager;
  return the_manager;
}

void GameAssetManager::addAsset(std::shared_ptr<GameAsset> the_asset) {
}

GameAssetManager::GameAssetManager() {
}

GameAssetManager::GameAssetManager(GameAssetManager const& the_manager) {
}

GameAssetManager::GameAssetManager(GameAssetManager const&& the_manager) {
}

void GameAssetManager::operator=(GameAssetManager const& the_manager) {
}
