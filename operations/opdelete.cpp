#include "opdelete.h"
opdelete::opdelete(controller* pCont) :operation(pCont) {} // consstructor 
void opdelete::Execute()
{
	Graph* pGraph = pControl->getGraph();
	pGraph->DELSHAPE(); // function implementation in graph files 
}

void opdelete::Undo()
{
	Graph* pGr = pControl->getGraph();
	pGr->AddToUndoStack();
}
void opdelete::Redo()
{
	Graph* pGr = pControl->getGraph();
	pGr->AddtoShapeList();
}