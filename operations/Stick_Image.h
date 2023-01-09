#pragma once
#include"operation.h"
class Stick_Image :public operation
{
public:
	Stick_Image(controller* pCont);
	void Execute();
};
