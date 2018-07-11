#include "Warrior.h"



Warrior::Warrior()
{
}

bool Warrior::isDead()
{
	return HP == 0;
}

bool Warrior::attackable(const Warrior* enemy)
{
	if (enemy->moveMode == "Air")
	{
		if (this->airAttack == 0)
			return false;
	}
	else return true;
}

int Warrior::getDamage()
{
		return groundAttack + airAttack;
}

Warrior::~Warrior()
{
}
