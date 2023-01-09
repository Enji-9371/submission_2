#pragma once

#include "operation.h"

//Add triangle operation class
class opAddTriangle : public operation
{
private : 
	Point P1, P2, P3;
	GfxInfo CtriangleGfxInfo;

public:
	opAddTriangle(controller* pCont);
	virtual ~opAddTriangle();

	//Add triangle to the controller
	virtual void Execute();

};

