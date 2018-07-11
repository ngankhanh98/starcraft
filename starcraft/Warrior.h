#pragma once
#include <iostream>
#include <string>
using namespace std;

class Warrior
{
protected:
	int HP;
	string moveMode;
	int groundAttack;
	int airAttack;
public:
	Warrior();
	bool isDead();
	bool attackable(const Warrior* enemy);
	virtual void display(ostream & out) = 0;
	virtual void setHP(int HP, int PS) = 0;
	int getDamage();
	~Warrior();
};

