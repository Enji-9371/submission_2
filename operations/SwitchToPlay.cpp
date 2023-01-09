#include "SwitchToPlay.h"

#include "operation.h"

#include "..\controller.h"

#include "..\GUI\GUI.h"


SwitchToPlay::SwitchToPlay(controller* pCont) :operation(pCont)
{}

void  SwitchToPlay::Execute()
{
	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();

	pUI->PrintMessage(" Switch to play mode.");

	pUI->ClearToolBar();

	pUI->CreatePlayToolBar();

	pUI->ClearStatusBar();

}
