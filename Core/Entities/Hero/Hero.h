#include"../../Libs/Libs.h"
#include"../Monster/Monster.h"

struct Hero
{
	uint32_t x_pos;
	uint32_t y_pos;

	uint32_t hp;
	uint32_t attack;
	uint32_t defence;
	string name;

	char texture;

	void action(string& field, int fieldSize, char move);
	int fight(Monster& monster);
	bool nearEnemy(string field, int fieldSize, char enemyTexture, int* fn, int* sn);
};