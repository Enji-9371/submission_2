#pragma once

#include "operation.h"

//Add Square operation class
class opAddSqur : public operation
{
public:
	opAddSqur(controller* pCont);
	virtual ~opAddSqur();

	//Add square to the controller
	virtual void Execute();

};

