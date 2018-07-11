#include "Zealot.h"



Zealot::Zealot()
{
	HP = 80;
	PS = 20;
	groundAttack = 16;
	airAttack = 0;
	moveMode = "Ground";
}

void Zealot::display(ostream & out)
{
	out << "Zealot (" << moveMode << "|" << HP << "/" << PS << ")";
}


Zealot::~Zealot()
{
}
