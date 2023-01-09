#include"Duplicate.h"
#include "../controller.h"
#include"../Shapes/Shape.h"


Duplicate::Duplicate(controller* pCont) : operation(pCont)
{}

void Duplicate::Execute()
{
	Graph* pGr = pControl->getGraph();
	GUI* pGUI = pControl->GetUI();
	pGr->Duplicated(pGUI);
}