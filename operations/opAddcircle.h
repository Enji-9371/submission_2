#pragma once

#include"operation.h"

//Add Circle operation class
class opAddCircle : public operation
{
public:
	opAddCircle(controller* pCont);
	virtual ~opAddCircle();

	//Add Circle to the controller
	virtual void Execute();

};
