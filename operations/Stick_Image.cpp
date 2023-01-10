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