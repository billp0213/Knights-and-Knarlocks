#include <vector>
#include <cmath>
#include <iostream>
#include "combat.h"



Combat::Combat() {
	player = new Player();
	enemies.push_back(new Character());
}

Combat::Combat(Player *player_in, Character* enemies_in, int numEnemies) {
	player = player_in;
	for (int i = 0; i < numEnemies; i++) {
		enemies.push_back(enemies_in);
		enemies_in++;
	}  
}

void Combat::battle() {
	int won = 0;
	int numEnemies = (int)enemies.size();
	while (*player->get_stats > 0 && won != numEnemies) {
		won = 0;
		playerTurn();
		for (int i = 0; i < numEnemies; i++) {
			if (*enemies[i]->get_stats > 0) {
				enemyTurn(enemies[i]);
			}
			else {
				won++;
			}
		}
	}
}

