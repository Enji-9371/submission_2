#pragma once
#include "operation.h"

class UnHide :public operation
{
public:
	UnHide(controller* pCont);
	virtual ~UnHide();
	virtual void Execute();
};