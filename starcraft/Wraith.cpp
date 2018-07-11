#include "Wraith.h"



Wraith::Wraith()
{
	HP = 120;
	groundAttack = 8;
	airAttack = 20;
	moveMode = "Air";
}

void Wraith::display(ostream & out)
{
	out << "Wraith (" << moveMode << "|" << HP << ")";
}


Wraith::~Wraith()
{
}
