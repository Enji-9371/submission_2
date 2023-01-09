#pragma once
#include "operation.h"


class  SwitchToDraw : public operation
{
public:
	SwitchToDraw(controller* pCont);
	virtual void Execute();

};

