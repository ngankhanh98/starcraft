#pragma once
#include <vector>
#include <ctime>
#include <Windows.h>
#include "Dragoon.h"
#include "Scout.h"
#include "Zealot.h"
#include "Firebat.h"
#include "Marine.h"
#include "Wraith.h"

class Starcraft
{
private:
	vector<Terran*> m_Terran;
	vector<Protoss*> m_Protoss;
public:
	Starcraft();
	void displayTerran(ostream & out);
	void displayProtoss(ostream & out);
	void attack(ostream & out, string mode);
	Warrior* find_Minimum_HP(string type);
	Warrior* find_Maximum_Damage(string type);
	void filter();
	void attack(ostream & out, string attacker, string victim, int mode);
	void attack_by_mode(ostream & out);
	void play(ostream & out);
	~Starcraft();
};

