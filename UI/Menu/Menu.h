#include"../../Core/Libs/Libs.h"
#include"../../Core/Entities/Boss/Boss.h"
#include"../../Core/Entities/Monster/Monster.h"
#include"../../Core/Entities/Field/Field.h"
#include"../../Core/Entities/Hero/Hero.h"


void menu()
{
	srand(time(NULL));
	Field mainField;
	Hero mainHero;
	//field settings
	mainField.fieldSize = 20;
	mainField.visiebleFieldSize = 5;
	mainField.emptySpace = ' ';

	//monsters settings
	int amountOfMonsters = 5;
	Monster* monsters = new Monster[amountOfMonsters];

	//hero settings
	mainHero.x_pos = 3;
	mainHero.y_pos = 2;
	mainHero.texture = 254;

	//field actions
	mainField.fillField();
	mainField.field[((mainField.fieldSize * 2 + 1) * mainHero.y_pos) + mainHero.x_pos] = mainHero.texture;
	
	
	for (int i = 0; i < amountOfMonsters; i++)
		monsters[i].randPos(mainField.field, mainField.fieldSize);
	for(int i=0;i<amountOfMonsters;i++)
		mainField.field[((mainField.fieldSize * 2 + 1) * monsters[i].y_pos) + monsters[i].x_pos] = monsters[i].texture;
	
	do
	{
		system("cls");
		mainField.printField();
		mainHero.action(mainField.field,mainField.fieldSize);
		mainHero.fight();
	} while (true);
}