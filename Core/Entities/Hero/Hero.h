#include"../../Libs/Libs.h"
#include"../Monster/Monster.h"

struct Hero
{
	uint32_t x_pos;
	uint32_t y_pos;

	int hp;
	int attack;
	int defence;
	string name;
	string* inventory;
	int inventoryMaxSlots;

	char texture;

	void action(string& field, int fieldSize, char move);
	int fight(Monster& monster);
	bool nearEnemy(string field, int fieldSize, char enemyTexture, int* fn, int* sn);
	void showInventory();
};