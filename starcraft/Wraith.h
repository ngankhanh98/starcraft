#pragma once
#include "Terran.h"

class Wraith: public Terran
{
public:
	Wraith();
	virtual void display(ostream & out);
	~Wraith();
};

