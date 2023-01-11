#pragma once
#include "operations/operation.h"

class Move : public operation
{
public:
	Move(controller* pCont);
	virtual ~Move();
	virtual void Execute();
	virtual void Undo() override;
	virtual void Redo() override;


};

