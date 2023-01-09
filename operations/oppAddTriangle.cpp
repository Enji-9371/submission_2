#include "opAddTriangle.h"
#include "..\shapes\Ctriangle.h"
#include "..\controller.h"
#include "..\GUI\GUI.h"

opAddTriangle::opAddTriangle(controller* pCont) :operation(pCont){}
opAddTriangle::~opAddTriangle(){}
//Execute the operation
void opAddTriangle::Execute()
{
	Point P1,P2,P3;
	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();
	pUI->PrintMessage("New Triangle: Click at first corner");
	//Read 1st corner and store in point P1
	
	pUI->GetPointClicked(P1.x, P1.y);
	string msg = "First corner is at (" + to_string(P1.x) + ", " + to_string(P1.y) + " )";
	msg += " ... Click at second corner\n";
	pUI->PrintMessage(msg);
	//Read 2nd corner and store in point P2
	pUI->GetPointClicked(P2.x, P2.y);
 msg += "second  corner is at (" + to_string(P2.x) + ", " + to_string(P2.y) + " )";
	msg += " ... Click at third corner \n";
	pUI->PrintMessage(msg);
	pUI->GetPointClicked(P3.x, P3.y);
	pUI->ClearStatusBar();
	//Preapre all triangle parameters
	GfxInfo CtriangleGfxInfo;

	//get drawing, filling colors and pen width from the interface
	CtriangleGfxInfo.DrawClr = pUI->getCrntDrawColor();
	CtriangleGfxInfo.FillClr = pUI->getCrntFillColor();
	CtriangleGfxInfo.BorderWdth = pUI->getCrntPenWidth();
	CtriangleGfxInfo.isFilled = pUI->GetIsFilled();;	//default is not filled
	CtriangleGfxInfo.isSelected = false;	//defualt is not selected
	//Create a rectangle with the above parameters
	Ctriangle* T = new Ctriangle(P1, P2, P3, CtriangleGfxInfo);
	//Get a pointer to the graph
	Graph* pGr = pControl->getGraph();
	//Add the rectangle to the list of shapes
	pGr->Addshape(T);

}
