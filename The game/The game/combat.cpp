#include <vector>
#include <cmath>
#include <iostream>
#include <cstdlib>
#include <time.h>
#include "combat.h"



Combat::Combat() {
	player = new Player();
	enemies->push_back(new Character());
}

Combat::Combat(Player *player_in, std::vector<Character*> * enemies_in, int numEnemies_in) {
	player = player_in;
	enemies = enemies_in;
	numEnemies = numEnemies_in;
	 
}

void Combat::displayStats() {
	double * pstats = player->get_stats();
	double * estats;
	std::cout << "Player Stats:\n HP: ";
	std::cout << *pstats++;
	std::cout << "\n Attack: ";
	std::cout << *pstats++;
	std::cout << "\n Defense: ";
	std::cout << *pstats++;
	std::cout << "\n Speed: ";
	std::cout << *pstats << "\n";
	for (int i = 0; i < numEnemies; i++) {
		estats = enemies->at(i)->get_stats();
		std::cout << "Enemy " << i + 1 << " Stats:\n HP: ";
		std::cout << *estats++;
		std::cout << "\n Attack: ";
		std::cout << *estats++;
		std::cout << "\n Defense: ";
		std::cout << *estats++;
		std::cout << "\n Speed: ";
		std::cout << *estats << "\n";
	}
}

void Combat::displayHP() {
	double * pstats = player->get_stats();
	double * estats;
	std::cout << "Player HP: " << *pstats << "\n";
	for (int i = 0; i < numEnemies; i++) {
		estats = enemies->at(i)->get_stats();
		std::cout << "Enemy " << i + 1 << " HP: " << *estats << "\n";
	}
}

void Combat::playerTurn() {
	std::cout << "Press 0 to attack all enemies, press 1-" << numEnemies << " to attack a single target\n";
	int target;
	double damage;
	std::cin >> target;
	std::cout << *(player->get_stats() + 1) << "\n";
	double r = (rand() % 100) / 100.0 + 1;
	std::cout << r << "\n";
	if (target == 0) {
		damage = *((player->get_stats())+1) * r;
		std::cout << damage;
		for (int i = 0; i < numEnemies; i++){
			enemies->at(i)->lose_health(damage - ((*(enemies->at(i)->get_stats() + 2)) * ((rand() % 100) / 100.0) + 1));
			if (*(enemies->at(i)->get_stats()) < 0) {
				enemies->at(i)->lose_health(*(enemies->at(i)->get_stats()));
			}
		}
	} 
	else {
		damage = *((player->get_stats())+1) * ((rand() % 100) / 100.0 + 1) * (rand() % numEnemies);
		enemies->at(target - 1)->lose_health(damage - ((*(enemies->at(1)->get_stats() + 2)) * ((rand() % 100) / 100.0 + 1)));
		if (*(enemies->at(target-1)->get_stats()) < 0) {
			enemies->at(target-1)->lose_health(*(enemies->at(target-1)->get_stats()));
		}
	}
}

void Combat::enemyTurn(Character * enemy_in) {
	double damage;
	damage = *((enemy_in->get_stats())+1) * ((rand() % 100) / 100.0);
	player->lose_health(damage);

}

void Combat::battle() {
	int won = 0;
	srand(time(NULL));
	displayStats();
	while (*player->get_stats() > 0 && won != numEnemies) {
		won = 0;
		playerTurn();
		for (int i = 0; i < numEnemies; i++) {
			if (*enemies->at(i)->get_stats() > 0) {
				enemyTurn(enemies->at(i));
			}
			else {
				won++;
			}
		}
		displayHP();
	}
}

