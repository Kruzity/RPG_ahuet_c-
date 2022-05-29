#include"../../Core/Libs/Libs.h"
#include"../../Core/Entities/Boss/Boss.h"
#include"../../Core/Entities/Field/Field.h"
#include"../../Core/Entities/Hero/Hero.h"


void escMenu()
{
	string leftSide[4], rightSide[4], menuItems[4]{"Return","Inventory","Oprions","Exit"};
	int arrowPos = 0;
	leftSide[arrowPos] = "->";
	rightSide[arrowPos] = "<-";
	for(int keyAction;;)
	{
		system("cls");
		cout << setw(5) << leftSide[0] << menuItems[0] << rightSide[0] << endl;
		cout << setw(4) << leftSide[1] << menuItems[1] << rightSide[1] << endl;
		cout << setw(5) << leftSide[2] << menuItems[2] << rightSide[2] << endl;
		cout << setw(6) << leftSide[3] << menuItems[3] << rightSide[3] << endl;

		keyAction = _getch();
		switch (keyAction)
		{
			case 13:
			{
				switch (arrowPos)
				{
					case 0:
					{
						return;
						break;
					}
					case 1:
					{
						//Написать инвентарь
						break;
					}
					case 2:
					{
						//Написать настройки
						break;
					}
					case 3:
					{
						exit(0);
						break;
					}
				}
				break;
			}

			default:
			{
				if (keyAction == 80 && arrowPos < 3)
				{
					swap(leftSide[arrowPos], leftSide[arrowPos + 1]);
					swap(rightSide[arrowPos], rightSide[arrowPos + 1]);
					arrowPos++;
				}
				else if (keyAction == 72 && arrowPos > 0)
				{
					swap(leftSide[arrowPos], leftSide[arrowPos - 1]);
					swap(rightSide[arrowPos], rightSide[arrowPos - 1]);
					arrowPos--;
				}
			}
		}
	}
}

void menu()
{
	srand(time(NULL));
	Field mainField;
	Hero mainHero;
	int fn[8]{-1,-1,-1,0,1,1,1,0}, sn[8]{-1,0,1,1,1,0,-1,-1};


	//field settings
	mainField.fieldSize = 20;
	mainField.visiebleFieldSize = 5;
	mainField.emptySpace = ' ';

	//monsters settings
	string monsterTypes[]{ "Kringe", "Pinkle", "Shrab", "Solf", "Palanda" };
	int amountOfMonsters = 5;
	Monster* monsters = new Monster[amountOfMonsters];
	//hero settings
	mainHero.x_pos = 3;
	mainHero.y_pos = 2;
	mainHero.texture = 254;
	mainHero.hp = 5;
	mainHero.attack = 1;
	mainHero.defence = 2;
	mainHero.name = "Kruzity";

	//field actions
	mainField.fillField();
	mainField.field[((mainField.fieldSize * 2 + 1) * mainHero.y_pos) + mainHero.x_pos] = mainHero.texture;
	
	
	for (int i = 0; i < amountOfMonsters; i++)
	{
		monsters[i].attack = rand() % 5;
		monsters[i].defence = rand() % 5;
		monsters[i].hp = rand() % 5;
		monsters[i].randPos(mainField.field, mainField.fieldSize);
		monsters[i].monsterType = monsterTypes[rand() % 5];
	}
	for(int i=0;i<amountOfMonsters;i++)
		mainField.field[((mainField.fieldSize * 2 + 1) * monsters[i].y_pos) + monsters[i].x_pos] = monsters[i].texture;
	
	char keyAction;
	//keyAction = _getch();
	//cout << (int)keyAction;
	int resultOfFight=0;
	do
	{
		system("cls");
		mainField.printField();
		if (resultOfFight == 1)
		{
			cout << " ____ ____ ____ _________ ____ ____ ____" << endl;
			cout << "||Y |||o |||u |||       |||D |||I |||E ||" << endl;
			cout << "||__|||__|||__|||_______|||__|||__|||__||" << endl;
			cout << "|/__\\|/__\\|/__\\|/_______\\|/__\\|/__\\|/__\\|" << endl;
			exit(0);
		}
		if (mainHero.nearEnemy(mainField.field, mainField.fieldSize, monsters[0].texture, fn, sn))
		{
			cout << "Near Monster!!!\nPress F to fight" << endl;
		}
		keyAction = _getch();
		switch ((int)keyAction)
		{
			case 27:
			{
				escMenu();
				break;
			}
			case 102:
			{
				if (mainHero.nearEnemy(mainField.field, mainField.fieldSize, monsters[0].texture, fn, sn))
				{
					for (int i = 0; i < 8; i++)
					{
						if (mainField.field[((mainField.fieldSize * 2 + 1) * (mainHero.y_pos + fn[i])) + mainHero.x_pos + sn[i]] == monsters[0].texture)
						{
							for (int j = 0; j < amountOfMonsters; j++)
							{
								if (monsters[j].y_pos == mainHero.y_pos + fn[i] && monsters[j].x_pos == mainHero.x_pos + sn[i])
								{
									resultOfFight = mainHero.fight(monsters[j]);
									break;
								}
							}
							break;
						}
					}
				}
				break;
			}
			default:
			{
				mainHero.action(mainField.field, mainField.fieldSize, keyAction);
				break;
			}
		}
	} while (true);
}