#include"Monster.h"

void Monster::randPos(string field, int fieldSize)
{
	bool isRand = false;
	do
	{
		x_pos = rand() % fieldSize*2;
		y_pos = rand() % fieldSize;
		cout<< field[((fieldSize * 2 + 1) * y_pos) + x_pos]<<endl;
		if (field[((fieldSize * 2 + 1) * y_pos) + x_pos] == ' ')
			isRand = true;
	} while(isRand == false);
}