#pragma once
#include "operation.h"

//match cards class
class opMatch : public operation
{
public:
	opMatch(controller* pCont);
	virtual ~opMatch();

	virtual void Execute();

};


