#include "Ungroup.h"
#include "..\controller.h"
#include "../CMUgraphicsLib/CMUgraphics.h"

opUngroup::opUngroup(controller* pCont) :operation(pCont)
{}
opUngroup::~opUngroup()
{}

//Execute the operation
void opUngroup::Execute()
{
	GUI* pUI = pControl->GetUI();
	Graph* pGr = pControl->getGraph();
	int num = -1;
	while (num < 0)
	{
		pUI->PrintMessage("Please Enter group number: ");
		num = stoi(pUI->GetSrting());
	}
	pGr->DeleteGroupNum(num);

}
void opUngroup::Undo()
{
	
}
void opUngroup::Redo()
{

}