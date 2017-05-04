#pragma once
#include <vector>
#include "Character.h"

class Combat {
public:
	Combat();
	Combat(Player *player_in, std::vector<Character*> * enemies_in, int numEnemies_in);
	void displayStats();
	void displayHP();
	void playerTurn();
	void enemyTurn(Character *enemy_in);
	void battle();

private:
	Player *player;
	std::vector<Character*> * enemies;
	int numEnemies;


};
