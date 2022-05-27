#include"../../Libs/Libs.h"

struct Hero
{
	uint32_t x_pos;
	uint32_t y_pos;

	uint32_t attack;
	uint32_t defence;

	char texture;

	void action(string& field, int fieldSize, char move);
	void fight();
	bool nearEnemy(string field, int fieldSize, char enemyTexture);
};