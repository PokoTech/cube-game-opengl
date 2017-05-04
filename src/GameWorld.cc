#include "GameWorld.h"

GameWorld::GameWorld (ApplicationMode mode) : asset_manager(std::make_shared<GameAssetManager>(mode)){
	CreateWorld();
	//std::cout << glm::to_string(asset_manager->GetCamera()->GetCoordinates()) << std::endl;

	auto cube = std::make_shared<CubeAsset>();
	cube->translate(10,0,10);
	cube->setColor(0.0, 1.0, 0.0);
	asset_manager->AddAsset(cube);
	baddies.push_back(cube);

}

void GameWorld::CreateWorld(){
	//read in from .level file // replace ApplicationMode with level == profit
  std::ifstream world("levels/level1.level");
	if(world.is_open()){


		char token;
		//get rid of preceeding comments
		while(!world.eof()){
			world >> token;
			if(token == '#')
				world.ignore(256, '\n');
		}
		uint x = 0, y = 0, z = 0;
		uint x_lim, y_lim, z_lim;
		//take in headers

		world >> x_lim >> y_lim >> z_lim;

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
				world.push_back(cube);
				break;
			  }
		case '2': {
				auto cube = std::make_shared<CubeAsset>();
				cube->translate(x, y, z);
				cube->setColor(1.0, 0.0, 0.0);
				asset_manager->AddAsset(cube);
				world.push_back(cube);
				break;
			  }
		default:
			break;
	}
}

// Currently only works with one size of cube
bool GameWorld::CheckCollision(GameAsset &a, GameAsset &b) {
	//one size fits all cube
	float size = 0.5;
	//get coordinates of cubes
	auto aCoord = a.getCoordinates();
	auto bCoord = b.getCoordinates();

	// checking collision with all axis
	return ((aCoord[0] - size) <= (bCoord[0] + size) &&
	        (aCoord[0] + size) >= (bCoord[0] - size) &&
				  (aCoord[1] - size) <= (bCoord[1] + size) &&
					(aCoord[1] + size) >= (bCoord[1] - size) &&
			 	  (aCoord[2] - size) <= (bCoord[2] + size) &&
					(aCoord[2] + size) >= (bCoord[2] - size));
}

bool GameWorld::CheckCollision(glm::vec3 &a, glm::vec3 &b) {
	//one size fits all cube
	float size = 0.5;
	// checking collision with all axis
	return ((a.x - size) <= (b.x + size) &&
	        (a.x + size) >= (b.x - size) &&
				  (a.y - size) <= (b.y + size) &&
					(a.y + size) >= (b.y - size) &&
			 	  (a.z - size) <= (b.z + size) &&
					(a.z + size) >= (b.z - size));
}



//All Game logic is handled here
void GameWorld::Update() {
	//Update game objects
	auto camera_pos = asset_manager->GetCamera()->GetCoordinates();
	// Every frame translate baddie toward player
	for(auto baddie : baddies){
		baddie->setDirection(camera_pos);
		baddie->translateInDir();
	}

	// Every frames translate bullet in direction
	for(auto bullet : bullets){
		//bullet->translate(bullet->getDirection());
	}




	// Collision between player and baddies
	for (auto baddie : baddies){
		auto baddie_pos = baddie->getCoordinates();
		if(CheckCollision(baddie_pos, camera_pos)){
			std::cout<<"ouch"<<std::endl;
		}
	}
	// Collision between baddies and bullets
	for(uint i = 0; i < bullets.size(); i++){
		for(uint j = 0; j < bullets.size(); j++){
			if(CheckCollision(*bullets[i], *baddies[j])){
				asset_manager->RemoveAsset(bullets[i]);
				asset_manager->RemoveAsset(baddies[j]);
				//i--; j--;
			}
		}
	}
}

void GameWorld::Draw() {
  asset_manager->Draw();
}

//load in the update camera into GameWorld
void GameWorld::UpdateCamera(Control_Key c, int x_rel, int y_rel){
	asset_manager->UpdateCamera(c, x_rel, y_rel);
}
