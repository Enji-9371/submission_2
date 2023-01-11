#include "MATCH.h"
#include "..\controller.h"


opMatch::opMatch(controller* pCont) :operation(pCont)
{}
opMatch::~opMatch()
{}



//Execute the operation
void opMatch::Execute()
{
	//Get a Pointer to the Input / Output Interfaces

	GUI* pUI = pControl->GetUI();
	Graph* pGraph = pControl->getGraph();
	pUI->PrintMessage("matching");
	//pGraph->MATCH( shape1, shape2);
	
}

void opMatch::Undo()
{
	Graph* pGr = pControl->getGraph();
	pGr->AddToUndoStack();
}
void opMatch::Redo()
{
	Graph* pGr = pControl->getGraph();
	pGr->AddtoShapeList();
}