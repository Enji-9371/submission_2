#include "opAddSqur.h"
#include "..\shapes\Squr.h"

#include "..\controller.h"

#include "..\GUI\GUI.h"

opAddSqur::opAddSqur(controller* pCont) :operation(pCont)
{}
opAddSqur::~opAddSqur()
{}

//Execute the operation
void opAddSqur::Execute()
{
	Point P1{}, P2{};

	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();

	pUI->PrintMessage("New Square: Click at first corner");
	//Read 1st corner and store in point P1
	pUI->GetPointClicked(P1.x, P1.y);

	string msg = "First corner is at (" + to_string(P1.x) + ", " + to_string(P1.y) + " )";
	msg += " ... Click at second corner";
	pUI->PrintMessage(msg);
	//Read 2nd corner and store in point P2
	pUI->GetPointClicked(P2.x, P2.y);
	pUI->ClearStatusBar();

	//Preapre all square parameters
	GfxInfo SqurGfxInfo;

	//get drawing, filling colors and pen width from the interface
	SqurGfxInfo.DrawClr = pUI->getCrntDrawColor();
	SqurGfxInfo.FillClr = pUI->getCrntFillColor();
	SqurGfxInfo.BorderWdth = pUI->getCrntPenWidth();


	SqurGfxInfo.isFilled = pUI->GetIsFilled();;	//default is not filled
	SqurGfxInfo.isSelected = false;	//defualt is not selected


	//Create a square with the above parameters
	Squr* R = new Squr(P1, P2, SqurGfxInfo);

	//Get a pointer to the graph
	Graph* pGr = pControl->getGraph();

	//Add the square to the list of shapes
	pGr->Addshape(R);

}


void opAddSqur::Undo()
{
	Graph* pGr = pControl->getGraph();
	pGr->AddToUndoStack();
}
void opAddSqur::Redo()
{
	Graph* pGr = pControl->getGraph();
	pGr->AddtoShapeList();
}