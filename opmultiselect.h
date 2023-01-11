#pragma once
#include "operations/operation.h"

class MULTISELECT :public operation
{
private:
public:
	MULTISELECT(controller* pCont);
	virtual ~MULTISELECT();

	//select a shape 
	virtual void Execute();
	virtual void Undo() override;
	virtual void Redo() override;


};
