#include "opRedo.h"
#include "GUI/GUI.h"
#include "controller.h"


opRedo::opRedo(controller* pCont) :operation(pCont) {}

opRedo::~opRedo() {};


void opRedo::Execute()
{
	GUI* pUI = pControl->GetUI();
	Graph* pGr = pControl->getGraph();

	if (pControl->PreviousUndone())
	{
		pControl->PreviousUndone()->Redo();
		pControl->Redo();
		pGr->isSaved = false;
	}
}


void opRedo::Undo() {}
void opRedo::Redo() {}