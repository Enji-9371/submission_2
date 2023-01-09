#pragma once
#include "operation.h"

//resize class
class opResize : public operation
{
     public:
    	opResize(controller* pCont);
    	virtual ~opResize();
	    virtual void Execute();
};


