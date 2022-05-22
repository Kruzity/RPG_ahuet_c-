#include"../../Core/Libs/Libs.h"
#include"../../Core/Entities/Boss/Boss.h"
#include"../../Core/Entities/Monster/Monster.h"
#include"../../Core/Entities/Field/Field.h"
#include"../../Core/Entities/Hero/Hero.h"


void menu()
{
	Field mainField;
	Hero mainHero;
	//field settings
	mainField.fieldSize = 10;
	mainField.visiebleFieldSize = 5;
	mainField.emptySpace = ' ';

	//hero settings
	mainHero.x_pos = 3;
	mainHero.y_pos = 2;
	mainHero.texture = 'X';

	//field actions
	mainField.fillField();
	mainField.field[((mainField.fieldSize * 2 + 1) * mainHero.y_pos) + mainHero.x_pos] = mainHero.texture;
	do
	{
		system("cls");
		mainField.printField();
		mainHero.action(mainField.field,mainField.fieldSize);
		
	} while (true);
}