#include "opAddEllip.h"
#include "..\shapes\Ellip.h"

#include "..\controller.h"

#include "..\GUI\GUI.h"

opAddEllip::opAddEllip(controller* pCont) :operation(pCont)
{}
opAddEllip::~opAddEllip()
{}

//Execute the operation
void opAddEllip::Execute()
{
	Point P1{}, P2{};

	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();

	pUI->PrintMessage("New Oval: Click at first corner");
	//Read 1st corner and store in point P1
	pUI->GetPointClicked(P1.x, P1.y);

	string msg = "First corner is at (" + to_string(P1.x) + ", " + to_string(P1.y) + " )";
	msg += " ... Click at second corner";
	pUI->PrintMessage(msg);
	//Read 2nd corner and store in point P2
	pUI->GetPointClicked(P2.x, P2.y);
	pUI->ClearStatusBar();

	//Preapre all ellipse parameters
	GfxInfo EllipGfxInfo;

	//get drawing, filling colors and pen width from the interface
	EllipGfxInfo.DrawClr = pUI->getCrntDrawColor();
	EllipGfxInfo.FillClr = pUI->getCrntFillColor();
	EllipGfxInfo.BorderWdth = pUI->getCrntPenWidth();


	EllipGfxInfo.isFilled = pUI->GetIsFilled();;	//default is not filled
	EllipGfxInfo.isSelected = false;	//defualt is not selected


	//Create an ellipse with the above parameters
	Ellip* R = new Ellip(P1, P2, EllipGfxInfo);

	//Get a pointer to the graph
	Graph* pGr = pControl->getGraph();

	//Add the ellipse to the list of shapes
	pGr->Addshape(R);

}

void opAddEllip::Undo()
{
	Graph* pGr = pControl->getGraph();
	pGr->AddToUndoStack();
}
void opAddEllip::Redo()
{
	Graph* pGr = pControl->getGraph();
	pGr->AddtoShapeList();
}