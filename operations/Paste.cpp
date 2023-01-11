#include "Paste.h"
#include "../controller.h"
#include "../GUI/GUI.h"


Paste::Paste(controller* pCont) :operation(pCont)
{}

void Paste::Execute()
{
	Point p1;
	GUI* pGUI = pControl->GetUI();
	Graph* pGraph = pControl->getGraph();
	pGUI->PrintMessage("Click at the drawing area where you want to paste your shapes");
	pGUI->GetPointClicked(p1.x, p1.y);
	pGraph->paste(p1);
	pGUI->ClearStatusBar();
}

void Paste::Undo()
{
	Graph* pGr = pControl->getGraph();
	pGr->AddToUndoStack();
}
void Paste::Redo()
{
	Graph* pGr = pControl->getGraph();
	pGr->AddtoShapeList();
}