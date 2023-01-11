#pragma once
#include "operation.h"


class  SwitchToDraw : public operation
{
public:
	SwitchToDraw(controller* pCont);
	virtual void Execute();
	virtual void Undo() override;
	virtual void Redo() override;

};

