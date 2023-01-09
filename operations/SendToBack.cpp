#include "SendToBack.h"
#include"../controller.h"
SendToBack::SendToBack(controller* pCont) :operation(pCont)
{}

void SendToBack::Execute()
{
	GUI* pUI = pControl->GetUI();
	Graph* pGraph = pControl->getGraph();
	SelectedFig = pGraph->GetSelected();
	if (!SelectedFig)
		pUI->PrintMessage("Error: NO FIGURE SELECTED!");
	else
	{
		pControl->SendtoBack(SelectedFig);
	}
}

