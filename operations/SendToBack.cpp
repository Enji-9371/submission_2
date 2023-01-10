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