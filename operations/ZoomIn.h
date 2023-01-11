#pragma once
#include "operation.h"

//zoom in class
class opZoomIn : public operation
{
public:
	opZoomIn(controller* pCont);
	virtual ~opZoomIn();

	virtual void Execute();
	virtual void Undo() override;
	virtual void Redo() override;


};

