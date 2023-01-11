#pragma once
#include "operation.h"

class Duplicate : public operation
{
public:
	Duplicate(controller* pCont);
	virtual void Execute();
	virtual void Undo() override;
	virtual void Redo() override;
};