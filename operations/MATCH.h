#pragma once
#include "operation.h"
#include"../Shapes/Shape.h"
#include"../Shapes/Graph.h"

//match cards class
class opMatch : public operation
{
public:
	opMatch(controller* pCont);
	virtual ~opMatch();

	virtual void Execute();
	virtual void Undo() override;
	virtual void Redo() override;

};


