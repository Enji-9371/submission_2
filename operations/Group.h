#pragma once
#include "operation.h"

//group class
class opGroup : public operation
{
public:
	opGroup(controller* pCont);
	virtual ~opGroup();

	virtual void Execute();
	virtual void Undo() override;
	virtual void Redo() override;

};
