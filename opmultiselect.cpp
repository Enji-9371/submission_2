
#include "opmultiselect.h"
#include "controller.h"
#include "GUI/GUI.h"
MULTISELECT::MULTISELECT(controller* pCont) :operation(pCont)
{

}
MULTISELECT::~MULTISELECT()
{}

//Execute the operation
void MULTISELECT::Execute()
{
	Point P;
	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();
	Graph* pGr = pControl->getGraph();
	pUI->PrintMessage("MULTI SELECT MODE ON ");
	pUI->GetPointClicked(P.x, P.y);
	if (pGr->Getshape(P.x, P.y))
	{	pGr->Getshape(P.x, P.y)->SetSelected(true);
	}
	else
	{	pGr->UnselectShapes();
		pUI->ClearStatusBar();
	}

}