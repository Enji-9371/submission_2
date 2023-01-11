#include"CUT.h"


cut::cut(controller* pCont) :operation(pCont){}

cut::~cut(void){}

void cut::Execute()
{

	GUI* pGUI = pControl->GetUI();
	Graph* pGraph = pControl->getGraph();
	pGraph->CCUT();
	pGUI->PrintMessage("CUT IS ON SELECT SHAPE");

}

void cut::Undo()
{
	Graph* pGr = pControl->getGraph();
	pGr->AddToUndoStack();
}
void cut::Redo()
{
	Graph* pGr = pControl->getGraph();
	pGr->AddtoShapeList();
}
