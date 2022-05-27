#include"Hero.h"

void Hero::action(string& field, int fieldSize, char move)
{
	if (move == -32)
		move = _getch();
	switch ((int)move)
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
			cout << (int)move << endl;
			Sleep(300);
		}
	}
}

void Hero::fight()
{
	system("cls");
	/*fstream fightScene;   Прикол с визуалом, но я пока не понимаю как сделать
	fightScene.open("\\1heroAttack.txt", ios::in);
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
				cout << "---------------------------------" << endl;;
				Sleep(100);
				i = 0;
				system("cls");
			}
		}
		fightScene.close();
	}*/

}

bool Hero::nearEnemy(string field,int fieldSize,char enemyTexture)
{
	if (field[((fieldSize * 2 + 1) * (y_pos - 1)) + x_pos - 1] == enemyTexture) return true;
	else if (field[((fieldSize * 2 + 1) * (y_pos - 1)) + x_pos + 0] == enemyTexture) return true;
	else if (field[((fieldSize * 2 + 1) * (y_pos - 1)) + x_pos + 1] == enemyTexture) return true;
	else if (field[((fieldSize * 2 + 1) * (y_pos + 0)) + x_pos + 1] == enemyTexture) return true;
	else if (field[((fieldSize * 2 + 1) * (y_pos + 1)) + x_pos + 1] == enemyTexture) return true;
	else if (field[((fieldSize * 2 + 1) * (y_pos + 1)) + x_pos + 0] == enemyTexture) return true;
	else if (field[((fieldSize * 2 + 1) * (y_pos + 1)) + x_pos - 1] == enemyTexture) return true;
	else if (field[((fieldSize * 2 + 1) * (y_pos + 0)) + x_pos - 1] == enemyTexture) return true;
	
	return false;
}