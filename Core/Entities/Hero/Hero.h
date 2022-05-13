#include"../../Libs/Libs.h"

struct Hero
{
	uint32_t x_pos;
	uint32_t y_pos;
	char texture;

	void action(int fieldSize);
	void fight();
};