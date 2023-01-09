#pragma once
#include "operation.h"

class Duplicate : public operation
{
public:
	Duplicate(controller* pCont);
	virtual void Execute();
};