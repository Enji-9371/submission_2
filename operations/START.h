#pragma once
#include "operation.h"

//zoom in class
class opStart : public operation
{
public:
	opStart(controller* pCont);
	virtual ~opStart();

	virtual void Execute();

};