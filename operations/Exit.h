#pragma once
#include "operation.h"
#include "../DEFS.h"
class Exit : public operation
{
private:
	string Write;
	string x;
public:
	Exit(controller* pCont);
	virtual ~Exit(void);
	virtual void Execute();
	virtual void Undo() override;
	virtual void Redo() override;
};

