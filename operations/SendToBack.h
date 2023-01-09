#pragma once
#include "operation.h"
#include "../Shapes/Shape.h"

class SendToBack : public operation
{
private:
	shape* SelectedFig;
public:
	SendToBack(controller* pCont);
	virtual void Execute();
};