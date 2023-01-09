#pragma once
#include "operation.h"
class opAddREGPolygon : public operation
{
public:
	opAddREGPolygon(controller* pCont);
	  virtual ~opAddREGPolygon();
	  virtual void Execute();
};