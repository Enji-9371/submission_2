#pragma once
#include "operation.h"

class Copy :public operation
{
public:
	Copy(controller* pCont);
	virtual void Execute();
};
