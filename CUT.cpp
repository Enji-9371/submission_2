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

