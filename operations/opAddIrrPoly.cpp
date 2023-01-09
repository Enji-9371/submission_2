#include "opAddIrrPoly.h"
#include "..\shapes\Irregpoly.h"

#include "..\controller.h"

#include "..\GUI\GUI.h"


opAdd_IIR_POLYGON::opAdd_IIR_POLYGON(controller* pCont) :operation(pCont)
{}
opAdd_IIR_POLYGON::~opAdd_IIR_POLYGON()
{}

//Execute the operation
void opAdd_IIR_POLYGON::Execute()
{


	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();

	pUI->PrintMessage("What is num of vertices  : ");
	string num = pUI->GetSrting();
	Point* ArrayOfPoints = new Point[stoi(num)];

	pUI->ClearStatusBar();
	for (int i = 0; i < stoi(num); i++)
	{
		pUI->GetPointClicked(ArrayOfPoints[i].x, ArrayOfPoints[i].y);
	}

	pUI->ClearStatusBar();



	//Preapre Circle parameters
	GfxInfo IRR_PolygonGfxInfo;

	//get drawing, filling colors and pen width from the interface
	IRR_PolygonGfxInfo.DrawClr = pUI->getCrntDrawColor();
	IRR_PolygonGfxInfo.FillClr = pUI->getCrntFillColor();
	IRR_PolygonGfxInfo.BorderWdth = pUI->getCrntPenWidth();
	IRR_PolygonGfxInfo.isFilled = false;	//default is not filled
	IRR_PolygonGfxInfo.isSelected = false;	//defualt is not selected


	//Create a Polygon with the above parameters
	irr_polygon* I = new irr_polygon(ArrayOfPoints, stoi(num), IRR_PolygonGfxInfo);


	//Get a pointer to the graph
	Graph* pGr = pControl->getGraph();

	//Add the Cicle to the list of shapes
	pGr->Addshape(I);

}


