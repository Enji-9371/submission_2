#include "opAddregpolygon.h"
#include "..\controller.h"

#include "..\GUI\GUI.h"

#include "..\shapes\Cregpolygon.h"

opAddREGPolygon::opAddREGPolygon(controller* pCont) :operation(pCont)
{}
opAddREGPolygon::~opAddREGPolygon()
{}
//Execute the operation
void opAddREGPolygon::Execute()
{
	Point P1, P2;
	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();
	pUI->PrintMessage("New polygon: Enter number of vertices");
	string num = pUI->GetSrting();
	//while (stoi(num) < 3)
	
		//pUI->PrintMessage("Enter a vailed number "
	//	num = pUI->GetSrting();

		pUI->PrintMessage("Click at the Center");
		//Read point and ore in point P1
		pUI->GetPointClicked(P1.x, P1.y);
		string msg = "The center is at (" + to_string(P1.x) + ", " + to_string(P1.y) + " )";
		msg += " ... click at any vertices";
		pUI->PrintMessage(msg);
		
		pUI->GetPointClicked(P2.x, P2.y);
		//Read end point and store in point P2		pUI->GetPointClicked(P2.x, P2.y);
		pUI->ClearStatusBar();
		//Preapre Circle parameters
		GfxInfo PolygonGfxInfo;
		//get drawing, filling colors and pen width from the interface
		PolygonGfxInfo.DrawClr = pUI->getCrntDrawColor();
		PolygonGfxInfo.FillClr = pUI->getCrntFillColor();
		PolygonGfxInfo.BorderWdth = pUI->getCrntPenWidth();
		PolygonGfxInfo.isFilled = false;	//default is not filled
		PolygonGfxInfo.isSelected = false;	//defualt is not selected
		PolygonGfxInfo.isSelected = false;	//defualt is not selecte
		//Create a Polygon with the above parameters
		//polygon* C = new polygon(P1, P2, stoi(num), PolygonGfxInfo);

		////Get a pointer to the graph
		//Graph* pGr = pControl->getGraph();
		//pGr->Addshape(C);

	
}