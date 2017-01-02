#include "GameWorld.h"

GameWorld::GameWorld (ApplicationMode mode) : asset_manager(std::make_shared<GameAssetManager>(mode)) {
	CreateWorld();
}

void GameWorld::CreateWorld(){
	//read in from .level file // replace ApplicationMode with level == profit
	std::ifstream world("levels/start.level");
	if(world.is_open()){

		uint x = 0, y = 0, z = 0;
		uint x_lim, y_lim, z_lim;
		//take in headers

		world >> x_lim >> y_lim >> z_lim;
		char token;

		while(!world.eof()){
			world >> token;
			if(token == '#'){
				//ignores lines starting with #
				world.ignore(256,'\n');
			}else{
				CheckToken(token, x, y, z);
				//increment placement variables.
				++x;
				if(x >= x_lim){ x = 0; ++z; }
				if(z >= z_lim){ z = 0; ++y; }
				if(y >= y_lim){ break; }
			}
		}
	}else{
		std::cout << "Failed to open file" << std::endl;
	}
	world.close();
}

void GameWorld::CheckToken(char token, uint x, uint y, uint z){
	switch(token){
		case '1': {
								auto cube = std::make_shared<CubeAsset>();
								cube->translate(x, y, z);
								asset_manager->AddAsset(cube);
								break;
							}
		case '2':
			break;
		default:
			break;
	}	
}

void GameWorld::Draw() {
  asset_manager->Draw();
}
