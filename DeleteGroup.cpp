#include "DeleteGroup.h"
#include "controller.h"
#include "CMUgraphicsLib/CMUgraphics.h"

DeleteGroup::DeleteGroup(controller* pCont) :operation(pCont)
{}
DeleteGroup::~DeleteGroup()
{}

//Execute the operation
void DeleteGroup::Execute()
{
	GUI* pUI = pControl->GetUI();
	Graph* pGr = pControl->getGraph();
	int num = -1;
	while (num < 0)
	{
		pUI->PrintMessage("Please Enter group number: ");
		num = stoi(pUI->GetSrting());
	}
	pGr->DeleteGroup(num);


}
void DeleteGroup::Undo() {}

void DeleteGroup::Redo() {}
