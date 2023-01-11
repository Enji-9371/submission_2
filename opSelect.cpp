#include "Shapes/Rect.h"
#include "opSelect.h"
#include "controller.h"
#include "GUI/GUI.h"

opSelect::opSelect(controller* pCont ) :operation(pCont)
{

}
opSelect::~opSelect()
{}

//Execute the operation
void opSelect::Execute()
{
	Point P;
	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();
	Graph* pGr = pControl->getGraph();
	pUI->PrintMessage("Select Your Firgure");
	pUI->GetPointClicked(P.x, P.y);
	if (pGr->Getshape(P.x, P.y))
	{
		pGr->UnselectShapes();
		pGr->Getshape(P.x, P.y)->SetSelected(true);
	}
	else
	{
	
		
		pGr->UnselectShapes();
		pUI->ClearStatusBar();
	}

}
void opSelect::Undo()
{
	Graph* pGr = pControl->getGraph();
	pGr->AddToUndoStack();
}
void opSelect::Redo()
{
	Graph* pGr = pControl->getGraph();
	pGr->AddtoShapeList();
}