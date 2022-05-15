#include"../../Core/Libs/Libs.h"
#include"../../Core/Entities/Boss/Boss.h"
#include"../../Core/Entities/Monster/Monster.h"
#include"../../Core/Entities/Field/Field.h"


void menu()
{
	Field mainField;
	Hero mainHero;
	//field settings
	mainField.fieldSize = 25;
	mainField.visiebleFieldSize = 5;
	mainField.border = 178;
	mainField.emptySpace = 176;

	//hero settings
	mainHero.x_pos = 3;
	mainHero.y_pos = 2;
	mainHero.texture = 'X';

	//field actions
	mainField.fillField();
	do
	{
		//system("cls");
		mainField.printFieldWHero(mainHero);
		if (_kbhit()) mainHero.action(mainField.fieldSize);
		Sleep(500);
	} while (true);
}