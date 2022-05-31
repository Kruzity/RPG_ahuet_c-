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
				//swap(field[((fieldSize * 2 + 1) * y_pos) + x_pos], field[((fieldSize * 2 + 1) * (y_pos-1)) + x_pos]);
				field[((fieldSize * 2 + 1) * y_pos) + x_pos] = ' ';
				y_pos--;
			}
			break;
		}
		case(75):
		{
			//left
			if (x_pos - 1 > 0)
			{
				//swap(field[((fieldSize * 2 + 1) * y_pos) + x_pos], field[((fieldSize * 2 + 1) * y_pos) + x_pos-1]);
				field[((fieldSize * 2 + 1) * y_pos) + x_pos] = ' ';
				x_pos--;
			}
			break;
		}
		case(77):
		{
			//right
			if (x_pos + 1 < fieldSize * 2 - 1)
			{
				//swap(field[((fieldSize * 2 + 1) * y_pos) + x_pos], field[((fieldSize * 2 + 1) * y_pos) + x_pos+1]);
				field[((fieldSize * 2 + 1) * y_pos) + x_pos] = ' ';
				x_pos++;
			}
			break;
		}
		case(80):
		{
			//down
			if (y_pos + 1 < fieldSize-1)
			{
				//swap(field[((fieldSize * 2 + 1) * y_pos) + x_pos], field[((fieldSize * 2 + 1) * (y_pos + 1)) + x_pos]);
				field[((fieldSize * 2 + 1) * y_pos) + x_pos] = ' ';
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

int Hero::fight(Monster& monster)
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
	int endFight = 0;
	char key;

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
		cout << "1 - Attack" << endl;
		cout << "2 - Defence" << endl;
		cout << "3 - Inventory" << endl;
		
		key = _getch();
		int a = rand() % 2 + 1;
		int chanceForHeal = rand() % 100 + 1;
		//1 - monster attack
		//else - monster defend
		if (key == 49)
		{
			if (a == 1)
			{
				defence -= monster.attack;
				if (defence < 0)
				{
					hp += defence;
					defence = 0;
				}
				monster.defence -= attack;
				if (monster.defence < 0)
				{
					monster.hp += monster.defence;
					monster.defence = 0;
				}
				cout << "\t--|You have attack|--" << endl;
				cout << "\t---|and deal " << attack - monster.defence << " damage|---" << endl;
				
				cout << "\t--|Monster have attack|--" << endl;
				cout << "\t---|and deal " << monster.attack -	defence << " damage|---" << endl;
			}
			else
				cout << "\t--|Monster defeat attack|--";
		}
		else if (key == 50)
		{
			if (a == 1)
			{
				cout << "\t--|You have counterattack|--" << endl;
				cout << "\t---|and deal " << attack * 2 - monster.defence << " damage|---" << endl;
				monster.defence -= attack*2;
				if (monster.defence < 0)
				{
					monster.hp += monster.defence;
					monster.defence = 0;
				}
			}
			else
				cout << "\t\t |Monster defence too|";
		}
		else if (key == 51)
		{
			showInventory();
			int k;
			cout << "\nEnter choice:"; cin >> k;
			cin.ignore();
			if (k > 0 && k <= inventoryMaxSlots)
			{
				if (inventory[k - 1].empty())
				{
					cout << "Empty slot" << endl;
				}
				else
				{
					inventory[k - 1].clear();
					cout << "\t-|Your hp has been restored for 2 point|-" << endl;
					hp += 2;
				}
			}
			if (a == 1)
			{
				defence -= monster.attack;
				if (defence < 0)
				{
					hp += defence;
					defence = 0;
				}
				cout << "\t--|Monster have attack|--" << endl;
				cout << "\t---|and deal " << monster.attack - defence << " damage|---" << endl;
			}
		}


		if (hp <= 0)
		{
			cout << "\n\n\t-|You DIED|-";
			endFight = 1;
		}
		else if (monster.hp <= 0)
		{
			cout << "\n\n\t-|Monster DIED|-";
			if (chanceForHeal >= 1)
			{
				cout << "\n\t-|Monster dropped Heal Potin|-";
				for (int i = 0; i < inventoryMaxSlots; i++)
				{
					if (inventory[i].empty())
					{
						inventory[i] = "Heal Potion - heals 2 HP";
						break;
					}
				}
			}
			endFight = 2;
		}
		Sleep(5000);
	} while (endFight == 0);

	return endFight;
}

bool Hero::nearEnemy(string field,int fieldSize,char enemyTexture, int* fn, int* sn)
{
	for (int i = 0; i < 8; i++)
	{
		if (field[((fieldSize * 2 + 1) * (y_pos + fn[i])) + x_pos + sn[i]] == enemyTexture) return true;
	}
	return false;
}

void Hero::showInventory()
{
	for (int i = 0; i < inventoryMaxSlots; i++)
	{
		if (inventory[i].empty()) cout <<'\t'<< i + 1 << ". " << "empty slot" << endl;
		else cout << '\t'<<i+1 << ". " << inventory[i] << endl;
	}
}