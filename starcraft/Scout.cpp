#include "Scout.h"



Scout::Scout()
{
	HP = 100;
	PS = 40;
	groundAttack = 8;
	airAttack = 28;
	moveMode = "Air";
}

void Scout::display(ostream & out)
{
	out << "Scout (" << moveMode << "|" << HP << "/" << PS << ")";
}

Scout::~Scout()
{
}
