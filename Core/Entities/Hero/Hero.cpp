#include"Hero.h"

void Hero::move(int fieldSize)
{
	char a = _getch();
	if (a == 'w'&& y_pos - 1 > 1)
	{
		y_pos--;
		cout << y_pos << " " << x_pos << endl;
	}
	else if (a == 's' && y_pos + 1 < fieldSize)
	{
		y_pos++;
		cout << y_pos << " " << x_pos << endl;
	}
	else if (a == 'a' && x_pos - 1 >1)
	{
		x_pos--;
		cout << y_pos << " " << x_pos << endl;
	}
	else if (a == 'd' && x_pos +1 <fieldSize)
	{
		x_pos++;
		cout << y_pos << " " << x_pos << endl;
	}
	else cout << "Unknown letter" << endl;
	
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