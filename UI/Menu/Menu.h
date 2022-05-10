#include"../../Core/Libs/Libs.h"
#include"../../Core/Entities/Boss/Boss.h"
#include"../../Core/Entities/Monster/Monster.h"
#include"../../Core/Entities/Field/Field.h"


void menu()
{
	Field mainField;
	Hero mainHero;
	//field settings
	mainField.fieldSize = 30;
	mainField.visiebleFieldSize = 5;
	mainField.border = '#';
	mainField.emptySpace = '.';

	//hero settings
	mainHero.x_pos = 5;
	mainHero.y_pos = 5;

	//field actions
	mainField.makeField();
	mainField.fillField();
	mainField.printField();
	for(int i=0;i<5;i++)
		mainHero.fight();
}