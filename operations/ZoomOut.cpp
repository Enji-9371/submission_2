#include "ZoomOut.h"
#include "..\controller.h"


opZoomOut::opZoomOut(controller* pCont) :operation(pCont)
{}
opZoomOut::~opZoomOut()
{}

//Execute the operation
void opZoomOut::Execute()
{
	GUI* pUI = pControl->GetUI();  //pointer to GUI
	pUI->ClearStatusBar();
	pUI->CreateDrawToolBar();
	pUI->ClearStatusBar();
	Graph* pGraph = pControl->getGraph();  //poinrt to graph
	pGraph->ZOOM_IN_OUT(0.8, 640, 310);  //zoom in and out acording to the scale factor around the origin

}