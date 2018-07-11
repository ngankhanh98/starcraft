#include "Protoss.h"



Protoss::Protoss()
{
}

void Protoss::attack(Terran* enemy)
{
	int HP = enemy->getHP();
	if (enemy->getMoveMode() == "Ground")
		HP = HP - this->groundAttack;
	if (enemy->getMoveMode() == "Air")
		HP = HP - this->groundAttack;
	if (HP < 0) HP = 0;
	enemy->setHP(HP);
}

void Protoss::viewAttack(Terran* enemy, ostream & out)
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

void Protoss::setHP(int HP, int PS)
{
	this->HP = HP;
	this->PS = PS;
}
Protoss::~Protoss()
{
}
