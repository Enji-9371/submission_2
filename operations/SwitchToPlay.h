#pragma once
#include "operation.h"


class  SwitchToPlay : public operation
{
public:
	SwitchToPlay(controller* pCont);
	virtual void Execute();

};

