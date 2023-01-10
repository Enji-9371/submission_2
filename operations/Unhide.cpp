#include "Unhide.h"
#include "../controller.h"
#include"../Shapes/Shape.h"

Unhide::Unhide(controller* pCont) : operation(pCont) 
{
}

void Unhide::Execute() {
	GUI* pUI = pControl->GetUI();
	Graph* pGraph = pControl->getGraph();
	pGraph->UnHide(pUI);
	pUI->PrintMessage("Shapes are Hidden");

}