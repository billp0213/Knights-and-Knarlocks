#pragma once
#include<vector>

class Character {
	public:
		Character() {};
		Character(int xPos_in, int yPos_in, int level_in, int multiplier)
			: xPos(xPos_in), yPos(yPos_in) {
			level = level_in;
			stats[0] = 10 + 2 * multiplier * level_in;
			stats[1] = multiplier * level_in;
			stats[2] = multiplier * level_in;
			stats[3] = multiplier * level_in;
		} 
		int get_xPos();
		int get_yPos();
		int get_level();
		int* get_stats();
		void set_stats(int level_in, int multiplier) {
			level = level_in;
			stats[0] = 10 + level_in * multiplier;
			stats[1] = level_in * multiplier;
			stats[2] = level_in * multiplier;
			stats[3] = level_in * multiplier;
		}
		void set_pos(int xPos_in, int yPos_in) {
			xPos = xPos_in;
			yPos = yPos_in;
		}
	private:
		int xPos;
		int yPos;
//hp, attack, defense, speed		
		int stats[4];
		int level;
};

class Player : public Character {
	public:
		Player() : Character() {
			auxStats[0] = 1;
			auxStats[1] = 1;
			auxStats[2] = 1;
			auxStats[3] = 1;
			Exp = 0;
		}
		Player(int xPos_in, int yPos_in, int level_in, int multiplier, int* aux_in, int Exp_in) : Character(xPos_in, yPos_in, level_in, multiplier) {
			auxStats[0] = aux_in[0];
			auxStats[1] = aux_in[1];
			auxStats[2] = aux_in[2];
			auxStats[3] = aux_in[3];
			Exp = Exp_in;
		}
		int* get_auxStats() {
			return auxStats;
		}
		int get_Exp() {
			return Exp;
		}
		void set_auxStats(int* aux_in) {
			auxStats[0] = aux_in[0];
			auxStats[1] = aux_in[1];
			auxStats[2] = aux_in[2];
			auxStats[3] = aux_in[3];
		}
		void set_Exp(int Exp_in) {
			Exp = Exp_in;
		}
	private:
		int auxStats[4];
		int Exp;
		int multiplier = 1;
};
