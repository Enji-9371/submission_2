#include "Resize.h"
#include "..\controller.h"

opResize::opResize(controller* pCont) :operation(pCont)
{}
opResize::~opResize()
{}

//Execute the operation
void opResize::Execute()   //resize a single shape
{
	GUI* pUI = pControl->GetUI();
	Graph* pGraph = pControl->getGraph();
	pUI->PrintMessage("ENTER THE SCALE(0.25 - 0.5 - 2 - 4) TO RESIZE : ");  
	double scale= stod(pUI->GetSrting());   //get the scale as a double
	pUI->ClearStatusBar();
	if (scale == 0.25 || scale == 0.5 || scale == 2 || scale == 4)
	{
		//pControl->getGraph()->RESIZE(scale);
		pUI->SetResized();
		pGraph->RESIZE(scale);
	}
	else
	{
		pUI->PrintMessage("UNSUPPORTED OPERATION!");
	}
}

void opResize::Undo()
{
	Graph* pGr = pControl->getGraph();
	pGr->AddToUndoStack();
}
void opResize::Redo()
{
	Graph* pGr = pControl->getGraph();
	pGr->AddtoShapeList();
}