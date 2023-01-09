#pragma once
#include "operation.h"
#include "../Shapes/Shape.h"
#include<vector>
class Hide : public operation
{
	vector <shape*> shapelist;
public:
	Hide(controller* pCont);
	virtual void Execute();
};