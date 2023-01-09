#pragma once

#include "operation.h"

class Copy : public operation
{
public:
	Copy(controller*);
	virtual void Execute();
};
