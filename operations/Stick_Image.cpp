#include "Stick_Image.h"
#include "../controller.h"
#include "../GUI/GUI.h"

Stick_Image::Stick_Image(controller* pCont) :operation(pCont)
{}

void Stick_Image::Execute()
{
	
	GUI* pUI = pControl->GetUI();

	Graph* pGr = pControl->getGraph();


	if (pGr->GetSelected())
	{

		pGr->GetSelected()->IsSticked = true;

	}
}

void Stick_Image::Undo()
{
	Graph* pGr = pControl->getGraph();
	pGr->AddToUndoStack();
}
void Stick_Image::Redo()
{
	Graph* pGr = pControl->getGraph();
	pGr->AddtoShapeList();
}