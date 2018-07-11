#pragma once
#include "Warrior.h"
#include "Terran.h"


class Protoss: public Warrior
{
	friend class Terran;
protected:
	int PS;
public:
	Protoss();
	void attack(Terran* enemy);
	void viewAttack(Terran* enemy, ostream & out);
	virtual void display(ostream & out) = 0;
	void setHP(int HP, int PS);
	int getHP() { return this->HP; }
	int getPS() { return this->PS; }
	string getMoveMode() { return this->moveMode; }
	~Protoss();
};

