#include "Starcraft.h"
#include <conio.h>


Starcraft::Starcraft()
{
	srand(time(NULL));
	//Terran: Marine, Firebat, Wraith
	//Protoss: Zealot, Dragon, Scout
	
	//Khoi tao cho vector terran*
	for (int i = 0; i < 5; i++)
	{
		Terran* obj;
		int key = rand() % 3;
		switch (key)
		{
		case 0:
			obj = new Marine;
			break;
		case 1:
			obj = new Firebat;
			break;
		case 2:
			obj = new Wraith;
			break;
		default:
			break;
		}
		m_Terran.push_back(obj);
	}
	//Khoi tao ch vector Protoss*
	//Protoss: Zealot, Dragon, Scout
	for (int i = 0; i < 5; i++)
	{
		Protoss* obj;
		int key = rand() % 3;
		switch (key)
		{
		case 0:
			obj = new Zealot;
			break;
		case 1:
			obj = new Dragoon;
			break;
		case 2:
			obj = new Scout;
			break;
		default:
			break;
		}
		m_Protoss.push_back(obj);
	}
}

void Starcraft::displayTerran(ostream & out)
{
	out << "<==Team A==>" << endl;
	for (int i = 0; i < m_Terran.size(); i++)
	{
		m_Terran[i]->display(out);
		out << endl;
	}
}

void Starcraft::displayProtoss(ostream & out)
{
	out << "<==Team B==>" << endl;
	for (int i = 0; i < m_Protoss.size(); i++)
	{
		m_Protoss[i]->display(out);
		out << endl;
	}
}

void Starcraft::attack(ostream & out, string mode)
{
	if (mode == "firstBlood")
	{
		for (int i = 0; i < 5; i++)
			m_Protoss[i]->viewAttack(m_Terran[i], out);
		return;
	}
	if (mode == "Avenge")
	{
		for (int i = 0; i < 5; i++)
			m_Terran[i]->viewAttack(m_Protoss[i], out);
		return;
	}
}

Warrior * Starcraft::find_Minimum_HP(string type)
{
	//Tim quan co mau it nhat trong team
	if (type == "Terran")
	{
		Terran* t_min = m_Terran[0];
		for (int i = 1; i < m_Terran.size(); i++)
		{
			if (m_Terran[i]->getHP() < t_min->getHP()) t_min = m_Terran[i];
		}
		return t_min;
	}
	else if (type == "Protoss")
	{
		Protoss* p_min = m_Protoss[0];
		for (int i = 1; i < m_Protoss.size(); i++)
		{
			if (m_Protoss[i]->getHP() < p_min->getHP()) p_min = m_Protoss[i];
		}
		return p_min;
	}
	else return nullptr;
}

Warrior * Starcraft::find_Maximum_Damage(string type)
{
	//Tim quan co tong tan cong lon nhat trong team
	if (type == "Terran")
	{
		Terran* t_max = m_Terran[0];
		for (int i = 1; i < m_Terran.size(); i++)
		{
			if (m_Terran[i]->getDamage() > t_max->getDamage()) t_max = m_Terran[i];
		}
		return t_max;
	}
	else if (type == "Protoss")
	{
		Protoss* p_max = m_Protoss[0];
		for (int i = 1; i < m_Protoss.size(); i++)
		{
			if (m_Protoss[i]->getDamage() > p_max->getDamage()) p_max = m_Protoss[i];
			return p_max;
		}
	}
	else return nullptr;
}

void Starcraft::filter()
{
	int t_size = m_Terran.size();
	int p_size = m_Protoss.size();
	for (int i = 0; i < t_size; i++)
	{
		if (m_Terran[i]->isDead()) {
			m_Terran.erase(m_Terran.begin() + i);
			t_size--;
		}
	}
	for (int i = 0; i <p_size; i++)
	{
		if (m_Protoss[i]->isDead()) {
			m_Protoss.erase(m_Protoss.begin() + i);
			p_size--;
		}
	}
}

void Starcraft::attack(ostream & out, string attacker, string victim, int mode)
{
	if (mode == 1)
	{
		srand(time(NULL));
		out << endl << attacker << " randomly attacked " << victim << "..." << endl;
		if (attacker == "Terran" && victim == "Protoss")
		{
			for (int i = 0; i < m_Protoss.size(); i++)
			{
				int n = rand() % m_Terran.size();
				int m = rand() % m_Protoss.size();
				m_Terran[n]->viewAttack(m_Protoss[m], out);
				this->filter();
			}
		}
		else if (attacker == "Protoss" && victim == "Terran")
		{
			for (int i = 0; i < m_Terran.size(); i++)
			{
				int n = rand() % m_Terran.size();
				int m = rand() % m_Protoss.size();
				m_Protoss[m]->viewAttack(m_Terran[n], out);
				this->filter();
			}
		}
		else return;
		Sleep(400);
	}
	else if (mode == 2)
	{
		srand(time(NULL));
		out << endl << attacker << " randomly attacked " << victim << " that is possible..." << endl;
		if (attacker == "Terran" && victim == "Protoss")
		{
			int eps = 0;
			for (int i = 0; i < m_Protoss.size(); i++)
			{
				int m;
				int n;
				do {
					n = rand() % m_Terran.size();
					m = rand() % m_Protoss.size();
					if (m_Terran[n]->attackable(m_Protoss[m]))
					{
						m_Terran[n]->viewAttack(m_Protoss[m], out);
						break;
					}
					eps++;
					if (eps > 20) break;
				} while (!m_Terran[n]->attackable(m_Protoss[m]));
				this->filter();
			}
			Sleep(400);
			return;
		}
		else if (attacker == "Protoss" && victim == "Terran")
		{
			int eps = 0;
			for (int i = 0; i < m_Terran.size(); i++)
			{
				int m;
				int n;
				do {
					n = rand() % m_Terran.size();
					m = rand() % m_Protoss.size();
					if (m_Protoss[m]->attackable(m_Terran[n]))
					{
						m_Protoss[m]->viewAttack(m_Terran[n], out);
						break;
					}
					eps++;
					if (eps > 20) break;
				} while (!m_Protoss[m]->attackable(m_Terran[n]));
				this->filter();
			}
			Sleep(400);
			return;
		}
		else return;
	}
	else if (mode == 3)
	{
		out << endl << attacker << " attacked attackable and least-HP " << victim << "..." << endl;
		if (attacker == "Terran" && victim == "Protoss")
		{
			for (int i = 0; i < m_Protoss.size(); i++)
			{
				Protoss* p_min = (Protoss*)find_Minimum_HP("Protoss");
				m_Terran[i % m_Terran.size()]->viewAttack(p_min, out);
				this->filter();
			}
		}
		else if (attacker == "Protoss" && victim == "Terran")
		{
			for (int i = 0; i < m_Terran.size(); i++)
			{
				Terran* t_min = (Terran*)find_Minimum_HP("Terran");
				m_Protoss[i % m_Protoss.size()]->viewAttack(t_min, out);
				this->filter();
			}
		}
		else return;
		Sleep(400);
	}
	else if (mode == 4)
	{
		out << endl << attacker << " attacked attackable and most powerful " << victim << "..." << endl;
		if (attacker == "Terran" && victim == "Protoss")
		{
			for (int i = 0; i < m_Protoss.size(); i++)
			{
				Protoss* p_max = (Protoss*)find_Maximum_Damage("Protoss");
				m_Terran[i % m_Terran.size()]->viewAttack(p_max, out);
				this->filter();
			}
		}
		else if (attacker == "Protoss" && victim == "Terran")
		{
			for (int i = 0; i < m_Terran.size(); i++)
			{
				Terran* t_max = (Terran*)find_Maximum_Damage("Terran");
				m_Protoss[i % m_Protoss.size()]->viewAttack(t_max, out);
				this->filter();
			}
		}
		else return;
		Sleep(400);
	}
}

void Starcraft::attack_by_mode(ostream & out)
{
	int mode;
	int n = 0;
	cout << "Choose attacking mode:\n";
	cout << "1. Randomly attack\n";
	cout << "2. Randomly attack enemy that is possible.\n";
	cout << "3. Attack attackable and least-HP enemy.\n";
	cout << "4. Attack attackable and most powerful enemy.\n";
	do {
		cout << "You choose "; cin >> mode;
		if (mode < 1 || mode > 4) out << "Wrong mode! Again!\n";
	} while (mode < 1 || mode > 4);

	while (m_Terran.size() != 0 && m_Protoss.size() != 0)
	{
		if (n % 2 == 0) {
			this->attack(out, "Protoss", "Terran", mode);
			n++;
			continue;
		}
		if (n % 2 == 1)
		{
			this->attack(out, "Terran", "Protoss", mode);
			n++;
			continue;
		}
	}
}

void Starcraft::play(ostream & out)
{
	out << "<=====Welcome to Starcraft III=====>\n";
	out << "------------------------------------\n";
	this->displayTerran(out);
	out << "------------------------------------\n";
	this->displayProtoss(out);
	out << "------------------------------------\n";
	out << "One day, Protosses attacked Terrans..." << endl;
	attack(out, "firstBlood");
	out << "\nAnd... Terrans decided to AVENGE.\n";
	attack(out, "Avenge");
	out << "\nAnd the war began...\n";
	this->attack_by_mode(out);
	Sleep(2000);
	out << endl << "\n<<============================>>";
	out << "\nAfter a long period of war...\n";
	if (m_Protoss.size() != 0)
	{
		Sleep(2500);
		out << "The last warrior of the Terrans has GONE!\n";
		Sleep(3000);
		out << "And the Protosses WON!\n";
		Sleep(2500);
	}
	if (m_Terran.size() != 0)
	{
		Sleep(3000);
		out << "The last warrior of the Protosses has GONE!\n";
		Sleep(2500);
		out << "And the Terrans WON!\n";
		Sleep(2500);
	}
	out << "<=====The End=====>\n";
	cout << "Press any key co continue...\n";
	_getch();
	out << "\n----------------------------------\n";
	out << "\t==STARCRAFT==\n";
	out << "A game by:\n";
	out << "1612288. Nguyen Khac Nguyen Khang\n";
	out << "1612291. Nguyen Thi Ngan Khanh\n";
	out << "1612296. Ta Ngoc Duy Khoa\n";
	out << "<<16CTT2-IT-HCMUS>>" << endl;
	cout << "Press any key to continue..." << endl;
}


Starcraft::~Starcraft()
{
}
