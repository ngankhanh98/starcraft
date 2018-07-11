#include "Firebat.h"



Firebat::Firebat()
{
	HP = 100;
	groundAttack = 18;
	airAttack = 0;
	moveMode = "Ground";
}

void Firebat::display(ostream & out)
{
	out << "Firebat (" << moveMode << "|" << HP << ")";
}


Firebat::~Firebat()
{
}
