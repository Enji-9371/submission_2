#pragma once
#include "operation.h"
#include "../Shapes/Shape.h"
#include<vector>

class Unhide : public operation

{
	vector <shape*> shapelist;

public:

	Unhide(controller* pCont);
	virtual void Execute();

};