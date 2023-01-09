#pragma once
#ifndef ROTATE_H
#define ROTATE_H
#include "operation.h"

//rotation class
class opRotate : public operation
{
private:
	Point P1, P2; //Rectangle Corners
	GfxInfo CircGfxInfo;
public:
	opRotate(controller* pCont);
	virtual ~opRotate();

	virtual void Execute();

};
#endif

