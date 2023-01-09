#include "SwitchToDraw.h"

#include "operation.h"

#include "..\controller.h"

#include "..\GUI\GUI.h"


SwitchToDraw::SwitchToDraw(controller* pCont) :operation(pCont)
{}

void  SwitchToDraw::Execute()
{
	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();

	pUI->PrintMessage(" Switch to draw mode.");

	pUI->ClearToolBar();

	pUI->CreateDrawToolBar();

	pUI->ClearStatusBar();
}
