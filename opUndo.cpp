#include"opUndo.h"

#include "controller.h"

#include "GUI/GUI.h"

opUndo::opUndo(controller* pCont) :operation(pCont) {}

opUndo::~opUndo() {}

void opUndo::Execute() {
	GUI* pUI = pControl->GetUI();
	Graph* pGr = pControl->getGraph();

	if (pControl->PreviousDone())
	{
		pControl->PreviousDone()->Undo();
		//pControl->Undo();
		pGr->isSaved = false;
	}

}

void opUndo::Undo() {}
void opUndo::Redo() {}