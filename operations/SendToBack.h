#pragma once
#include "operation.h"
#include<vector>
class SendToBack : public operation
{
public:
	SendToBack(controller* pCont);
	virtual void Execute();
	virtual void Undo() override;
	virtual void Redo() override;

};