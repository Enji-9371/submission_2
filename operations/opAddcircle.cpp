#include "opAddcircle.h"
#include "..\shapes\Ccircle.h"

#include "..\controller.h"

#include "..\GUI\GUI.h"

opAddCircle::opAddCircle(controller* pCont) :operation(pCont)
{}
opAddCircle::~opAddCircle()
{}

//Execute the operation
void opAddCircle::Execute()
{
	Point P1, P2;

	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();
	pUI->PrintMessage("NEW CIRCLE : Click ON THE RADUIS ");
	//Read 1st corner and store in point P1
	pUI->GetPointClicked(P1.x, P1.y);

	string msg = "CENTER is at (" + to_string(P1.x) + ", " + to_string(P1.y) + " )";
	msg += " ... Click at second corner";
	pUI->PrintMessage(msg);
	//Read 2nd corner and store in point P2
	pUI->GetPointClicked(P2.x, P2.y);
	pUI->ClearStatusBar();

	//Preapre all rectangle parameters
	GfxInfo CcirclefxInfo;

	//get drawing, filling colors and pen width from the interface
	CcirclefxInfo.DrawClr = pUI->getCrntDrawColor();
	CcirclefxInfo.FillClr = pUI->getCrntFillColor();
	CcirclefxInfo.BorderWdth = pUI->getCrntPenWidth();


	CcirclefxInfo.isFilled = pUI->GetIsFilled();	//default is not filled
	CcirclefxInfo.isSelected = false;	//defualt is not selected


	//Create a rectangle with the above parameters
	Ccircle* R = new Ccircle(P1, P2, CcirclefxInfo);

	//Get a pointer to the graph
	Graph* pGr = pControl->getGraph();

	//Add the rectangle to the list of shapes
	pGr->Addshape(R);

}
