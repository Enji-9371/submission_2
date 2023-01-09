#pragma once

#include "operation.h"

//Add Ellipse operation class
class opAddEllip : public operation
{
public:
	opAddEllip(controller* pCont);
	virtual ~opAddEllip();

	//Add ellipse to the controller
	virtual void Execute();

};

