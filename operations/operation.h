#pragma once
#include "..\DefS.h"
#include "..\GUI\GUI.h"

class controller; //forward class declaration


//Base class for all possible operations
class operation
{
protected:
	controller *pControl;	//operations needs control to do their job

public:

	operation(controller *pCont) { pControl = pCont; }	//constructor
	virtual ~operation(){}

	//Execute operation (code depends on operation type)
	virtual void Execute() =0;
	virtual void Undo()=0;
	virtual void Redo()=0;


	
};

