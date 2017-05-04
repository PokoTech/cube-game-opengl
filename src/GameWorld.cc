#include "GameWorld.h"

GameWorld::GameWorld (ApplicationMode mode) : asset_manager(std::make_shared<GameAssetManager>(mode)){
	//CreateWorld();
	//std::cout << glm::to_string(asset_manager->GetCamera()->GetCoordinates()) << std::endl;

}

void GameWorld::CreateWorld(){
	//read in from .level file // replace ApplicationMode with level == profit
  std::ifstream world("levels/level1.level");
	if(world.is_open()){


		char token;

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

bool GameWorld::CheckCollision(std::shared_ptr<GameAsset> &a, std::shared_ptr<GameAsset> &b){
	return CheckCollision(*a, *b);
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
	game_timer++;
	auto camera_pos = asset_manager->GetCamera()->GetCoordinates();

	// Spawn new baddies
	if(game_timer % spawn_rate == 0){
		auto baddie = std::make_shared<CubeAsset>();
		int x = rand() % 30 + 10;
		if(rand() % 2) x *= -1;
		int z = rand() % 30 + 10;
		if(rand() % 2) z *= -1;
		baddie->translate(x, 1.0f, z);
		baddie->setColor(0.0, 1.0, 0.0);
		asset_manager->AddAsset(baddie);
		baddies.push_back(baddie);
	}

	//reduce spawn_rate
	if(game_timer % reduce_rate == 0 && spawn_rate >= 1){
		spawn_rate -= 4;
	}

	// Every frame translate baddies toward player
	for(auto baddie : baddies){
		baddie->setDirection(camera_pos);
		baddie->translateInDir();
	}

	// Every frames translate bullet in direction
	float radius = 20;
	for (uint i = 0; i < bullets.size(); i++){
		bullets[i]->translateInDir();
		if(glm::length(bullets[i]->getCoordinates() - camera_pos) >= radius){
			asset_manager->RemoveAsset(bullets[i]);
			bullets.erase(bullets.begin() + i);
		}
	}

	// Collision between player and baddies
	for (uint i = 0; i < baddies.size(); i++){
		auto baddie_pos = baddies[i]->getCoordinates();
		if(CheckCollision(baddie_pos, camera_pos)){
			health--;
			std::cout<< "Ouch!!!"  <<std::endl;
			std::cout<< "Health : " << health <<std::endl;
			asset_manager->RemoveAsset(baddies[i]);
			baddies.erase(baddies.begin() + i);
		}
	}
	// Collision between baddies and bullets
	for(uint i = 0; i < bullets.size(); i++){
		for(uint j = 0; j < baddies.size(); j++){
			if(CheckCollision(bullets[i], baddies[j])){
				//std::cout<<"baddieHit"<<std::endl;
				score++;
				asset_manager->RemoveAsset(bullets[i]);
				bullets.erase(bullets.begin() + i);
				asset_manager->RemoveAsset(baddies[j]);
				baddies.erase(baddies.begin() + j);
			}
		}
	}
}

void GameWorld::Draw() {
  asset_manager->Draw();
}

// Creates a bullet from the players perspective
void GameWorld::FireBullet(){
	if(!firedBullet){
		firedBullet = true;
		auto bullet = std::make_shared<CubeAsset>();
		auto camera_pos = asset_manager->GetCamera()->GetCoordinates();
		auto camera_dir = asset_manager->GetCamera()->GetRotation();
		bullet->translate(camera_pos);
		bullet->setDirection(camera_dir);
		bullet->setColor(0.0, 1.0, 0.0);
		asset_manager->AddAsset(bullet);
		bullets.push_back(bullet);
	}
}


//load in the update camera into GameWorld
void GameWorld::UpdateCamera(Control_Key c, int x_rel, int y_rel){

	//quick nasty way to get the player shooting
	switch(c){
		case MOUSE_D:
			FireBullet();
			break;
		case MOUSE_U:
			firedBullet = false;
			break;
		default:
			break;
	}

	asset_manager->UpdateCamera(c, x_rel, y_rel);

	// Player stops on collision with world objects
	auto camera_pos = asset_manager->GetCamera()->GetCoordinates();
	for(auto element : world){
		auto element_pos = element->getCoordinates();
		if(CheckCollision(camera_pos, element_pos)){
			asset_manager->GetCamera()->RevertToLast();
		}
	}

}
