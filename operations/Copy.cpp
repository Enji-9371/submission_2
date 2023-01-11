#include "Copy.h"
#include "../controller.h"
#include"../Shapes/Shape.h"

Copy::Copy(controller* pCont) :operation(pCont)
{
}

void Copy::Execute()
{
	GUI* pGUI = pControl->GetUI();
	Graph* pGraph = pControl->getGraph();
    pGraph->copy();
	pGUI->PrintMessage("Selected shapes have been copied");
}
void Copy::Undo()
{
}
void Copy::Redo()
{
}