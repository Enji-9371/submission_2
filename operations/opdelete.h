#pragma once
#include "operation.h"
#include "../GUI/GUI.h"
#include "../controller.h"
#include "../Shapes/Graph.h"
#include "../Shapes/Ccircle.h"
#include "../Shapes/Rect.h"
#include "../Shapes/Ctriangle.h"
#include "../Shapes/Line.h"
#include "../Shapes/Graph.h"

//class opdelate that inherites from operation 
class opdelete : public operation
{
public:
	opdelete(controller* pCont); // pointer from controller type 
	virtual void Execute(); // virtual void execuute function

	virtual void Undo() override;
	virtual void Redo() override;


};