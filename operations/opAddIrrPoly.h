#pragma once
#include"operation.h"
class opAdd_IIR_POLYGON :public operation
{

public:
	opAdd_IIR_POLYGON(controller* pCont);
	virtual ~opAdd_IIR_POLYGON();

	virtual void Execute();

};

