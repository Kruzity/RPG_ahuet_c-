#include"Field.h"

void Field::fillField()
{
	string all(fieldSize, border), part(fieldSize - 2, emptySpace);
	for (int i = 0; i < fieldSize; i++)
	{
		if (i == 0 || i == fieldSize - 1)
			field[i] = all;
		else
		{
			field[i] += '#';
			field[i] += part;
			field[i] += '#';
		}
	}

}

void Field::printField()
{
	for (int i = 0; i < fieldSize; i++)
	{
		for (int j = 0; j < fieldSize; j++)
			cout << field[i][j] << " ";
		cout << endl;
	}
}

void Field::makeField()
{
	field = new string[fieldSize];
}

void Field::printVisiebleFieldsPart(Hero person)
{
	if (person.y_pos - visiebleFieldSize >= 0 && person.y_pos + visiebleFieldSize <= fieldSize && person.x_pos - visiebleFieldSize >= 0 && person.x_pos + visiebleFieldSize <= fieldSize)
	{
		for (int i = person.y_pos - visiebleFieldSize; i <= person.y_pos + visiebleFieldSize; i++)
		{
			for (int j = person.x_pos - visiebleFieldSize; j <= person.x_pos + visiebleFieldSize; j++)
				cout << field[i][j] << " ";
			cout << endl;
		}
	}
}
