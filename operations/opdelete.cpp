#include "opdelete.h"
opdelete::opdelete(controller* pCont) :operation(pCont) {} // consstructor 
void opdelete::Execute()
{
	Graph* pGraph = pControl->getGraph();
	pGraph->DeleteShapeFromList(); // function implementation in graph files 
}