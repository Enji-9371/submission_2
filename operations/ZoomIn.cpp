#include "ZoomIn.h"
#include "..\controller.h"


opZoomIn::opZoomIn(controller* pCont) :operation(pCont)
{}
opZoomIn::~opZoomIn()
{}

//Execute the operation
void opZoomIn::Execute()
{
	GUI* pUI = pControl->GetUI();    //pointer to GUI
	pUI->ClearStatusBar();
	pUI->CreateDrawToolBar();
	pUI->ClearStatusBar();
	Graph* pGraph = pControl->getGraph();  //POINTER TO GRAPH
	pGraph->ZOOM_IN_OUT(1.2, 640, 310);   //zoom in and out acording to the scale factor around the origin

}