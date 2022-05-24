#include"../../Libs/Libs.h"

struct Monster
{
	uint32_t x_pos;
	uint32_t y_pos;
	
	uint32_t attack;
	uint32_t defence;

	char texture = 31;

	void randPos(string field, int fieldSize);
};