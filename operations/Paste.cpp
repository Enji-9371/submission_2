#include "Paste.h"
#include "../controller.h"
#include "../GUI/GUI.h"


Paste::Paste(controller* pCont) :operation(pCont)
{}

void Paste::Execute()
{
	GUI* pUI = pControl->GetUI();

	shape* pntr1, * pntr2;

	if (pControl->GetClipboard())
	{
		GUI* pUI = pControl->GetUI();

		pUI->PrintMessage("Click on the Drawing Area to paste");

		pUI->GetPointClicked(p1.x, p1.y);

		pUI->ClearStatusBar();

		pntr1 = pControl->GetClipboard();

		pntr2 = pntr1->Paste(p1);

		pControl->AddShape(pntr2);

	}

	else
	{
		pUI->PrintMessage("please copy or cut a shape first");
	}
}