#pragma once
#include "operation.h"

//zoom in class
class opZoomIn : public operation
{
public:
	opZoomIn(controller* pCont);
	virtual ~opZoomIn();

	virtual void Execute();

};

