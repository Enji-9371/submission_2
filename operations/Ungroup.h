#pragma once
#include "operation.h"

//ungroup class
class opUngroup : public operation
{
public:
	opUngroup(controller* pCont);
	virtual ~opUngroup();

	virtual void Execute();
	virtual void Undo() override;
	virtual void Redo() override;

};

