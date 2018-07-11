#pragma once
#include "Terran.h"
class Marine: public Terran
{
public:
	Marine();
	virtual void display(ostream & out);
	~Marine();
};

