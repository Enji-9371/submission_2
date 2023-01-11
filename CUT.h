#pragma once
#include "operations/operation.h"
#include "controller.h"
#include "GUI/GUI.h"


class cut :public operation
{

public:
	cut(controller* pCont);
	virtual ~cut(void);

	//Execute action (code depends on action type)
	virtual void Execute();
	virtual void Undo() override;
	virtual void Redo() override;

};

