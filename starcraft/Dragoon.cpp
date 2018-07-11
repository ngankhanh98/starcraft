#include "Dragoon.h"



Dragoon::Dragoon()
{
	HP = 90;
	moveMode = "Ground";
	groundAttack = 20;
	airAttack = 20;
	PS = 30;
}

void Dragoon::display(ostream & out)
{
	out << "Dragoon (" << moveMode << "|" << HP << "/" << PS << ")";
}

Dragoon::~Dragoon()
{
}
