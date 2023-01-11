#pragma once

#include "operations/operation.h"

//group class
class DeleteGroup : public operation
{
public:
	DeleteGroup(controller* pCont);
	virtual ~DeleteGroup();

	virtual void Execute();
	virtual void Undo() override;
	virtual void Redo() override;

};
