#include "Hide.h"
#include "../controller.h"

Hide::Hide(controller* pCont) :operation(pCont) {}
Hide::~Hide() {}

void Hide::Execute() {

	GUI* pUI = pControl->GetUI();
	Graph* pGr = pControl->getGraph();

	pGr->Hide_shapes(pUI);
}

void Hide::Undo()
{
	Graph* pGr = pControl->getGraph();
	pGr->AddToUndoStack();
}
void Hide::Redo()
{
	Graph* pGr = pControl->getGraph();
	pGr->AddtoShapeList();
}