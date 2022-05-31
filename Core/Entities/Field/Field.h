#include"../../Libs/Libs.h"

struct Field
{
	uint32_t fieldSize;
	string field;
	char emptySpace;
	char border;

	uint32_t visiebleFieldSize;

	void fillField();
	void printField();
	void clearField();
	//void printFieldWHero(Hero arg);
};