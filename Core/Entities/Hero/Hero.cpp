#include"Hero.h"

void Hero::action(string& field, int fieldSize)
{
	char a = _getch();
	if (a == -32)
		a = _getch();
	switch ((int)a)
	{
		case(72):
		{
			//up
			if (y_pos - 1 > 0)
			{
				swap(field[((fieldSize * 2 + 1) * y_pos) + x_pos], field[((fieldSize * 2 + 1) * (y_pos-1)) + x_pos]);
				y_pos--;
			}
			break;
		}
		case(75):
		{
			//left
			if (x_pos - 1 > 0)
			{
				swap(field[((fieldSize * 2 + 1) * y_pos) + x_pos], field[((fieldSize * 2 + 1) * y_pos) + x_pos-1]);
				x_pos--;
			}
			break;
		}
		case(77):
		{
			//right
			if (x_pos + 1 < fieldSize * 2 - 1)
			{
				swap(field[((fieldSize * 2 + 1) * y_pos) + x_pos], field[((fieldSize * 2 + 1) * y_pos) + x_pos+1]);
				x_pos++;
			}
			break;
		}
		case(80):
		{
			//down
			if (y_pos + 1 < fieldSize-1)
			{
				swap(field[((fieldSize * 2 + 1) * y_pos) + x_pos], field[((fieldSize * 2 + 1) * (y_pos + 1)) + x_pos]);
				y_pos++;
			}
			break;
		}
		case(119):
		{
			//w

			break;
		}
		case(97):
		{
			//a
			break;
		}
		case(115):
		{
			//s
			break;
		}
		case(100):
		{
			//d
			break;
		}
		default:
		{
			cout << (int)a << endl;
			Sleep(300);
		}
	}
}

void Hero::fight()
{
	system("cls");
	fstream fightScene;
	fightScene.open("C:\\fight.txt", ios::in);
	if (fightScene.is_open())
	{
		int i = 0;
		string ahuet;
		while (getline(fightScene, ahuet))
		{
			cout << ahuet << endl;
			i++;
			if (i == 7)
			{
				Sleep(300);
				i = 0;
				system("cls");
			}
		}
		fightScene.close();
	}
}