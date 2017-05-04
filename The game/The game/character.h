#pragma once
#include<vector>

class Character {
	public:
		Character();
		Character(int xPos_in, int yPos_in, int level_in, int multiplier);
		int get_xPos();
		int get_yPos();
		int get_level();
		double* get_stats();
		void set_level(int level_in);
		void set_stats(int level_in, int multiplier);
		void set_pos(int xPos_in, int yPos_in);
		void lose_health(double hp_in);
	private:
		int xPos;
		int yPos;
		int level;
//hp, attack, defense, speed		
		double stats[4];
		
};

class Player : public Character {
	public:
		Player();
		Player(int xPos_in, int yPos_in, int level_in, int multiplier, int* aux_in, int Exp_in);
		int* get_auxStats();
		int get_exp();
		void set_auxStats(int* aux_in);
		void add_exp(int exp_in);
		void levelUp();
	private:
		//intellect, luck, magic, ????
		int auxStats[4];
		int exp;
		int multiplier;
};
