#pragma once
#include "operation.h"

class Hide :public operation
{
public:
	Hide(controller* pCont);
	virtual ~Hide();
	virtual void Execute();
};