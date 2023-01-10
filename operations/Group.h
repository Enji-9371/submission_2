#pragma once
#include "operation.h"
class Group : public operation
{
public:
	Group(controller* pCont);
	virtual void Execute();
};


