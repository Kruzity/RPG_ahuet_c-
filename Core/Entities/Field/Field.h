#include"../../Libs/Libs.h"
#include"../Hero/Hero.h"

struct Field
{
	uint32_t fieldSize;
	string field;
	char emptySpace;
	char border;

	uint32_t visiebleFieldSize;

	void fillField();
	void printField();
	void printFieldWHero(Hero arg);
};