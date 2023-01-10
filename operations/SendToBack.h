#pragma once
#include "operation.h"
#include<vector>
class SendToBack : public operation
{
public:
	SendToBack(controller* pCont);
	virtual void Execute();
};