#include "Group.h"
#include "..\controller.h"
#include "../CMUgraphicsLib/CMUgraphics.h"

opGroup::opGroup(controller* pCont) :operation(pCont)
{}
opGroup::~opGroup()
{}

//Execute the operation
void opGroup::Execute()
{
	GUI* pUI = pControl->GetUI();
	Graph* pGr = pControl->getGraph();
	int num = -1;

	pUI->PrintMessage("Please Enter group number:         (ENTER 0 TO EXIT)");
	num = stoi(pUI->GetSrting());
	if (num != 0)
		pGr->AddGroupNum(num);

}
void opGroup::Undo() {}
void opGroup::Redo(){}