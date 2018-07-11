#include "Marine.h"



Marine::Marine()
{
	HP = 80;
	groundAttack = 12;
	airAttack = 12;
	moveMode = "Ground";
}

void Marine::display(ostream & out)
{
	out << "Marine (" << moveMode << "|" << HP << ")";
}

Marine::~Marine()
{
}
