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

void Hero::fight(Monster& monster)
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

	do
	{
		system("cls");
		cout << name << setw(20 + monster.monsterType.length()) << right << monster.monsterType << endl;
		for (int i = 0; i < name.length(); i++) cout << '-';
		for (int i = 0; i < 20; i++) cout << ' ';
		for (int i = 0; i < monster.monsterType.length(); i++) cout << '-';
		cout << endl;
		cout << "Your HP: " << hp << setw(30) << right << " Monster HP : " << monster.hp << endl;
		cout << "Your Attack: " << attack << setw(30) << right << " Monster Attack : " << monster.attack << endl;
		cout << "Your Def: " << defence << setw(30) << right << " Monster Def : " << monster.defence << endl;
		
		cout << "____________________________________________________" << endl;
	} while (true);
}

bool Hero::nearEnemy(string field,int fieldSize,char enemyTexture, int* fn, int* sn)
{
	for (int i = 0; i < 8; i++)
	{
		if (field[((fieldSize * 2 + 1) * (y_pos + fn[i])) + x_pos + sn[i]] == enemyTexture) return true;
	}
	return false;
}