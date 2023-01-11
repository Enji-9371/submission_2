#include "Rotate.h"
#include "..\controller.h"

opRotate::opRotate(controller* pCont) :operation(pCont)
{}
opRotate::~opRotate()
{}

//Execute the operation
void opRotate::Execute()
{
	pControl->getGraph()->ROTATE();

}

void opRotate::Undo()
{
	Graph* pGr = pControl->getGraph();
	pGr->AddToUndoStack();
}
void opRotate::Redo()
{
	Graph* pGr = pControl->getGraph();
	pGr->AddtoShapeList();
}