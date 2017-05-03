#include "Character.h"

Character::Character() {
	xPos = 0;
	yPos = 0;
	level = 0;
	for (int i = 0; i < 4; i++) {
		stats[i] = 0;
	}
}

Character::Character(int xPos_in, int yPos_in, int level_in, int multiplier) : xPos(xPos_in), yPos(yPos_in) {
	set_stats(level_in, multiplier);
}

int Character::get_xPos() {
	return xPos;
}

int Character::get_yPos() {
	return yPos;
}

int Character::get_level() {
	return level;
}

int * Character::get_stats() {
	return &stats[0];
}

void Character::set_level(int level_in) {
	level = level_in;
}

void Character::set_pos(int xPos_in, int yPos_in) {
	xPos = xPos_in;
	yPos = yPos_in;
}

void Character::set_stats(int level_in, int multiplier) {
	level = level_in;
	stats[0] = 20 + level * multiplier * 10;
	stats[1] = 1 + level * multiplier;
	stats[2] = 1 + level * multiplier;
	stats[3] = 1 + level * multiplier;
}

Player::Player() : Character() {
	exp = 0;
	for (int i = 0; i < 4; i++) {
		auxStats[i] = 0;
	}
	multiplier = 1;
}

Player::Player(int xPos_in, int yPos_in, int level_in, int multiplier_in, int* aux_in, int exp_in) : Character(xPos_in, yPos_in, level_in, multiplier_in) {
	exp = exp_in;
	for (int i = 0; i < 4; i++) {
		auxStats[i] = *aux_in;
		aux_in++;
	}
	multiplier = multiplier_in;
}

int * Player::get_auxStats() {
	return &auxStats[0];
}

int Player::get_exp() {
	return exp;
}

void Player::set_auxStats(int * aux_in) {
	for (int i = 0; i < 4; i++) {
		auxStats[i] = *aux_in;
		aux_in++;
	}
	
}

void Player::add_exp(int exp_in) {
	exp += exp_in;
}

void Player::levelUp() {
	int lvl = get_level();
	set_level(lvl++);
	exp = 0;
	set_stats(lvl, multiplier);
	
}