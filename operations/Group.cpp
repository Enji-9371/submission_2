#include "Group.h"
#include "../controller.h"
#include "../GUI/GUI.h"

Group::Group(controller* pCont) :operation(pCont)
{}

void Group::Execute()
{
	Graph* pGr = pControl->getGraph();
	//pGr->Groupshapes();
}
