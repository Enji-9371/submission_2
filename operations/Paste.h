#pragma once
#include "operation.h"
class Paste :public operation
{
private:
	Point p1;
public:
	Paste(controller* pCont);
	virtual void Execute();
	virtual void Undo() override;
	virtual void Redo() override;

};
