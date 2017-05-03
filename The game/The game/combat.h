#pragma once
#include <vector>
#include "Character.h"

class Combat {
public:
	Combat();
	Combat(Player *player_in, Character *enemies_in, int numEnemies);
	void displayStats();
	void playerTurn();
	void enemyTurn(Character *enemy_in);
	void battle();

private:
	Player *player;
	std::vector<Character*> enemies;


};
