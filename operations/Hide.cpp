#include "Hide.h"
#include "../controller.h"
#include"../Shapes/Shape.h"

Hide::Hide(controller* pCont) : operation(pCont)
{
}

void Hide::Execute() 
{
	GUI* pUI = pControl->GetUI();
	Graph* pGraph = pControl->getGraph();
	pGraph->Hide(pUI);
	pUI->PrintMessage("Shapes are Hidden");
}