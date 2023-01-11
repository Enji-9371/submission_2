#pragma once
#include "operation.h"


class  SwitchToPlay : public operation
{
public:
	SwitchToPlay(controller* pCont);
	virtual void Execute();
	virtual void Undo() override;
	virtual void Redo() override;


};

