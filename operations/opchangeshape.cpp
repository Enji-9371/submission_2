#include "../operations/opchangeshape.h"
#include "..\CMUgraphicsLib\colors.h"
#include "..\Shapes\Shape.h"
#include "..\controller.h"
#include "..\GUI\GUI.h"


//==================================================================================//
//							color pallette               							//
//==================================================================================//

opClrPlt::opClrPlt(controller* pCont) :operation(pCont)
{}
opClrPlt::~opClrPlt()
{}

////Execute the operation
void opClrPlt::Execute()
{
	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();
	//create the color tool bar 
	return_CreateColorBar = pUI->CreateColorBar();

	if (return_CreateColorBar == dChangeToRed || return_CreateColorBar == dChangeToGreen || return_CreateColorBar == dChangeToBlue || return_CreateColorBar == dChangeToYellow || return_CreateColorBar == dChangeToBlack)
	{
		pUI->setCrntDrawColor(return_CreateColorBar);
	}
	else if (return_CreateColorBar == fChangeToRed || return_CreateColorBar == fChangeToGreen || return_CreateColorBar == fChangeToBlue || return_CreateColorBar == fChangeToYellow || return_CreateColorBar == fChangeToBlack)
	{
		pUI->setCrntFillColor(return_CreateColorBar);
	}

	// clear the status bar
	pUI->ClearStatusBar();

	pUI->CreateDrawToolBar(); //create new draw tool bar 
}




//==================================================================================//
//							changing width              							//
//==================================================================================//

opPenWidth::opPenWidth(controller* pCont) :operation(pCont)
{}
opPenWidth::~opPenWidth()
{}

////Execute the operation
void opPenWidth::Execute()
{
	GUI* pUI = pControl->GetUI();
	pUI->PrintMessage("Enter The New Width [10,20,30,40,50,60,70,80,90,100] : ");  
	 string wchoice = pUI->GetSrting();  //save the input

	 if (wchoice == "10")                //case in which the user wants the width to be very thin/small 
	 {
		 pUI->setCrntPenWidth(1);        //set current pen windth to 1 
	 }
	 else if (wchoice == "20")
	 {
		 pUI->setCrntPenWidth(4);
	 }
	 else if (wchoice == "30")
	 {
		 pUI->setCrntPenWidth(7);
	 }
	 else if (wchoice == "40")
	 {
		 pUI->setCrntPenWidth(10);
	 }
	 else if (wchoice == "50")
	 {
		 pUI->setCrntPenWidth(14);
	 }
	 else if (wchoice == "60")
	 {
		 pUI->setCrntPenWidth(19);
	 }
	 else if (wchoice == "70")
	 {
		 pUI->setCrntPenWidth(25);
	 }
	 else if (wchoice == "80")
	 {
		 pUI->setCrntPenWidth(30);
	 }
	 else if (wchoice == "90")
	 {
		 pUI->setCrntPenWidth(40);
	 }
	 else if (wchoice == "100")
	 {
		 pUI->setCrntPenWidth(50);
	 }
	 else                                  //if the input was out of range
	 {
		 pUI->PrintMessage("Unsupported Operation");
	 }

	// clear the status bar
	pUI->ClearStatusBar();
}




//==================================================================================//
//							changing in selected shape              				//
//==================================================================================//



opChngSelInfo::opChngSelInfo(controller* pCont) :operation(pCont)
{}
opChngSelInfo::~opChngSelInfo()
{}
////Execute the operation
void opChngSelInfo::Execute()
{
	Graph* pGraph = pControl->getGraph();
	GUI* pUI = pControl->GetUI();
	shape* pShape = pGraph->GetSelected();
	if (pShape->IsSelected() == true)
	{
		pUI->PrintMessage("Press 'D' to Change Drawing Color, 'F' to Change Filling Color, 'W' to change the width : ");
		string sel_choice = pUI->GetSrting();
		pUI->ClearStatusBar(); //clear the status bar
		if (sel_choice == "d" || sel_choice == "D" || sel_choice == "F" || sel_choice == "f")
		{


			pUI->PrintMessage("Press 'R' for RED, 'G' for GREEN,'BL' for BLUE, 'Y' for Yellow, 'BK' for BLACK");
			string sel_clr = pUI->GetSrting();
			pUI->ClearStatusBar(); //clear the status bar
			if (sel_choice == "d" || sel_choice == "D")
			{

				if (sel_clr == "R" || sel_clr == "r")
				{
					pShape->ChngDrawClr(RED);
				}
				else if (sel_clr == "G" || sel_clr == "g")
				{
					pShape->ChngDrawClr(GREEN);
				}
				else if (sel_clr == "BL" || sel_clr == "bl" || sel_clr == "Bl" || sel_clr == "bL")
				{
					pShape->ChngDrawClr(BLUE);
				}
				else if (sel_clr == "Y" || sel_clr == "y")
				{
					pShape->ChngDrawClr(YELLOW);
				}
				else if (sel_clr == "BK" || sel_clr == "bk" || sel_clr == "Bk" || sel_clr == "bK")
				{
					pShape->ChngDrawClr(BLACK);
				}
				else
				{
					pUI->PrintMessage("Unspported Operation! ");
				}
			}
			else if (sel_choice == "F" || sel_choice == "f")
			{
				if (sel_clr == "R" || sel_clr == "r")
				{
					pShape->ChngFillClr(RED);
				}
				else if (sel_clr == "G" || sel_clr == "g")
				{
					pShape->ChngFillClr(GREEN);
				}
				else if (sel_clr == "BL" || sel_clr == "bl" || sel_clr == "Bl" || sel_clr == "bL")
				{
					pShape->ChngFillClr(BLUE);
				}
				else if (sel_clr == "Y" || sel_clr == "y")
				{
					pShape->ChngFillClr(YELLOW);
				}
				else if (sel_clr == "BK" || sel_clr == "bk" || sel_clr == "Bk" || sel_clr == "bK")
				{
					pShape->ChngFillClr(BLACK);
				}
				else
				{
					pUI->PrintMessage("Unspported Operation! ");
				}
			}
		}
		else if (sel_choice == "w" || sel_choice == "W")
		{
			pUI->PrintMessage("Enter The New Width [from 1 to 5]: ");
			string sel_clr = pUI->GetSrting();
			pUI->ClearStatusBar(); //clear the status bar

			if (sel_clr == "1")
			{
				pShape->ChngDrawWidth(1);
			}
			else if (sel_clr == "2")
			{
				pShape->ChngDrawWidth(4);
			}
			if (sel_clr == "3")
			{
				pShape->ChngDrawWidth(7);
			}
			else if (sel_clr == "4")
			{
				pShape->ChngDrawWidth(10);
			}
			else if (sel_clr == "5")
			{
				pShape->ChngDrawWidth(15);
			}
			else
			{
				pUI->PrintMessage("Unspported Operation! ");
			}
		}
		else
		{
			pUI->PrintMessage("Unspported Operation! ");
		}

	}
}













