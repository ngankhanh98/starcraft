#pragma once
#include "Protoss.h"

class Scout : public Protoss
{
public:
	Scout();
	virtual void display(ostream & out);
	~Scout();
};

