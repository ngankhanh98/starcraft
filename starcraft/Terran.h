#pragma once
#include "Warrior.h"
#include "Protoss.h"


class Terran: public Warrior
{
	friend class Protoss;
public:
	Terran();
	void attack(Protoss* enemy);
	void viewAttack(Protoss* enemy, ostream & out);
	
	virtual void display(ostream & out) = 0;
	virtual void setHP(int HP, int PS = 0)
	{
		this->HP = HP;
	}

	int getHP() { return this->HP; }
	string getMoveMode() { return this->moveMode; }
	~Terran();
};

