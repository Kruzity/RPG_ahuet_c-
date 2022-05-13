#include"Field.h"

void Field::fillField()
{
	string all, part;
	for (int i = 0; i <= fieldSize * 2; i++)
	{
		all += border;

		if (i == 0 || i == fieldSize * 2) part += border;
		else
		{
			if(i%2==0)
				part += emptySpace;
			else
				part += ' ';
		}
	}
	for (int i = 0; i < fieldSize; i++)
	{
		if (i == 0 || i == fieldSize - 1)
		{
			field += all;
			field += '\n';
		}
		else
		{
			field += part;
			field += '\n';
		}
	}

}

void Field::printField()
{
	cout << field;
}

void Field::printFieldWHero(Hero arg)
{
	for (int i = 0; i <= fieldSize * 2; i++)
	{
		if (field[i] == arg.texture) field[i] = emptySpace;
	}
	field[((fieldSize*2+3)*(arg.y_pos)+(arg.x_pos+2))-1] = arg.texture;
	cout << field;
}


