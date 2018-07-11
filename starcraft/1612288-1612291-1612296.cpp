#include "Starcraft.h"
#include <fstream>
#include <conio.h>

void main()
{
	Starcraft st;
	fstream out;
	out.open("zLog.txt", ios::out);
	int save;
	cout << "Do you want to save the process in log file or display on the console?" << endl;
	do {
		cout << "(1. Log file || 2. Console)";
		cin >> save;
		if (save != 1 && save != 2) cout << "Again!" << endl;
	} while (save != 1 && save != 2);
	if (save == 1)
	{
		system("cls");
		st.play(out);
	}
	else
	{
		system("cls");
		st.play(cout);
	}
	_getch();
}