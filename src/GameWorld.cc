#include "GameWorld.h"

GameWorld::GameWorld (ApplicationMode mode) : asset_manager(std::make_shared<GameAssetManager>(mode)) {
	CreateWorld();
	//translateCamera();
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
//Loads cube assets into the game world and specifies location and colour in multiple cases for variation of cubes.
void GameWorld::CheckToken(char token, uint x, uint y, uint z){
	switch(token){
		case '1': {
				auto cube = std::make_shared<CubeAsset>();
				cube->translate(x, y, z);
				cube->setColor(0.0, 1.0, 0.0);
				asset_manager->AddAsset(cube);
				break;
			  }
		case '2': {
				auto cube = std::make_shared<CubeAsset>();
				cube->translate(x, y, z);
				cube->setColor(1.0, 0.0, 0.0);
				asset_manager->AddAsset(cube);
				break;
			  }
		default:
			break;
	}
}

void GameWorld::Draw() {
  asset_manager->Draw();
}

//load in the update camera into GameWorld
void GameWorld::UpdateCamera(Control_Key c, int x_rel, int y_rel){
	asset_manager->UpdateCamera(c, x_rel, y_rel);
}
