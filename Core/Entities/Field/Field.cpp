#include"Field.h"

void Field::clearField()
{
	field.clear();
}

void Field::fillField()
{
	string upPart, downPart, middlePart;
	for (int i = 0; i < fieldSize*2; i++)
	{
		if (i == 0)
		{
			upPart += 201;
			downPart += 200;
			middlePart += 186;
		}
		else if (i == fieldSize * 2 - 1)
		{
			upPart += 187;
			downPart += 188;
			middlePart += 186;
		}
		else
		{
			upPart += 205;
			downPart += 205;
			middlePart += ' ';
		}
	}
	for (int i = 0; i < fieldSize; i++)
	{
		if (i == 0) field += upPart;
		else if (i == fieldSize - 1) field += downPart;
		else field += middlePart;
		field += '\n';
	}

}

void Field::printField()
{
	cout << field;
}

//void Field::printFieldWHero(Hero arg)
//{
//	for (int i = 0; i < field.length(); i++)
//	{
//		if (field[i] == arg.texture) field[i] = emptySpace;
//	}
//	field[((fieldSize*2+1)*arg.y_pos)+arg.x_pos] = arg.texture;
//	cout << field;
//}


