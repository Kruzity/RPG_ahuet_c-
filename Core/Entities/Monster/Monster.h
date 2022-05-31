#include"../../Libs/Libs.h"

struct Monster
{
	uint32_t x_pos;
	uint32_t y_pos;
	
	string monsterType;
	int hp;
	int attack;
	int defence;

	char texture;

	void randPos(string field, int fieldSize);
};