#include "MATCH.h"
#include "..\controller.h"


opMatch::opMatch(controller* pCont) :operation(pCont)
{}
opMatch::~opMatch()
{}



//Execute the operation
void opMatch::Execute()
{
	//Get a Pointer to the Input / Output Interfaces

	GUI* pUI = pControl->GetUI();
	pUI->PrintMessage("matching");

	
}