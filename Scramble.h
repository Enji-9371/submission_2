#pragma once
#include "operations\operation.h"

class opScramble : public operation
{

public:
	opScramble(controller* pCont);
	virtual ~opScramble();
	virtual void Execute();
	virtual void Undo() override;
	virtual void Redo() override;
};
