#include "SendToBack.h"
#include "../controller.h"
#include "../GUI/GUI.h"
#include <fstream>
SendToBack::SendToBack(controller* pCont) : operation(pCont) {}

void SendToBack::Execute() 
{
	GUI* pUI = pControl->GetUI();
	Graph* pGraph = pControl->getGraph();
	pGraph->Sendtoback(pUI);
	pUI->PrintMessage("Shape send to back");
}

void SendToBack::Undo()
{
	Graph* pGr = pControl->getGraph();
	pGr->AddToUndoStack();
}
void SendToBack::Redo()
{
	Graph* pGr = pControl->getGraph();
	pGr->AddtoShapeList();
}