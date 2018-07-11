#include "Terran.h"



Terran::Terran()
{
}

void Terran::attack(Protoss* enemy)
{
	int PS = enemy->getPS();
	int HP = enemy->getHP();
	if (enemy->getMoveMode() == "Ground")
	{
		PS = PS - this->groundAttack;
		if (PS < 0)
		{
			HP = HP + PS;
			PS = 0;
		}
	}
	if (enemy->getMoveMode() == "Air")
	{
		PS = PS - this->airAttack;
		if (PS < 0)
		{
			HP = HP + PS;
			PS = 0;
		}
	}
	if (HP < 0) HP = 0;
	enemy->setHP(HP, PS);
}
void Terran::viewAttack(Protoss* enemy, ostream & out)
{
	if (enemy->isDead()) {
		enemy->display(out);
		out << " is dead." << endl;
		return;
	}
	this->display(out); out << " attacks "; enemy->display(out);
	this->attack(enemy);
	out << " >>>>> "; enemy->display(out);
	out << endl;
}

Terran::~Terran()
{
}
