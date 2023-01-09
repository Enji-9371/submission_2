#include "controller.h"
#include "operations/opAddRect.h"
#include "operations/opAddtriangle.h"
#include "operations/opAddcircle.h"
#include "operations/opAddregpolygon.h"
#include "operations/opAddIrrPoly.h"
#include "operations/opAddSqur.h"
#include "operations/opAddLine.h"
#include "operations/opAddEllip.h"
#include "operations/SwitchToDraw.h"
#include "operations/SwitchToPlay.h"
#include"operations/opchangeshape.h"
#include"operations/MATCH.h"
#include"operations/START.h"
#include"operations/ZoomIn.h"
#include"operations/ZoomOut.h"
#include "operations/Exit.h"
#include"operations/Group.h"
#include"operations/Ungroup.h"
#include"operations/Rotate.h"
#include "operations\opsave.h"
#include "operations/Copy.h"
#include "operations/Paste.h"
#include "operations/Resize.h"
#include "opmultiselect.h" 
#include "opmovebydrag.h"
#include "operations/operation.h"
#include "operations/SendToBack.h"
#include "operations/Duplicate.h"
#include "GUI/GUI.h"
#include "opSelect.h"
#include "operations/opdelete.h"
//Constructor
controller::controller()
{
	pGraph = new Graph;
	pGUI = new GUI;	//Create GUI object
}

//==================================================================================//
//								operations-Related Functions							//
//==================================================================================//
operationType controller::GetUseroperation() const
{
	//Ask the input to get the operation from the user.
	return pGUI->GetUseroperation();		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an operation and executes it
operation* controller::createOperation(operationType OpType)
{
	operation* pOp = nullptr;
	
	//According to operation Type, create the corresponding operation object
	switch (OpType)
	{
		case DRAW_RECT:
			pOp = new opAddRect(this);
			break;

		case DRAW_TRI:
			pOp = new opAddTriangle(this);
			break;

		case DRAW_CIRC:
			pOp = new opAddCircle(this);
			break;
		
		case DRAW_RPOLY:
			pOp = new opAddREGPolygon(this); 
			break;

		case DRAW_LINE:
			pOp = new opAddLine(this);
			break;

		case DRAW_SQUR:
			pOp = new opAddSqur(this);
			break;

		case DRAW_ELLIP:
			pOp = new opAddEllip(this);
			break;

		case DRAW_IRREGPOLY:
			pOp = new opAdd_IIR_POLYGON(this);
			break;

		case TO_DRAW:
			pOp = new SwitchToDraw(this);
			break;

		case MATCH:
			pOp = new opMatch(this);
			break;

		case START:
			pOp = new opStart(this);
			break;

		case TO_PLAY:
			pOp = new SwitchToPlay(this);
			break;

		case COLOR_PALETTE:   //color palette icon 
			pOp = new opClrPlt(this);
			break;

		case PEN_WIDTH:               //pen width icon
			pOp = new opPenWidth(this);
			break;
		case SELECT:
			pOp = new opSelect(this);
			break;

		case ROTATE:   //rotate a shape
			pOp = new opRotate(this);
			break;

		case ZOOM_IN:   //zoom in
			pOp = new opZoomIn(this);
			break;

		case ZOOM_OUT:   //zoom out
			pOp = new opZoomOut(this);
			break;

		case RESIZE:   //resize
			pOp = new opResize(this);
			break;

		case GROUP:   //group
			pOp = new opGroup(this);
			break;

		case UNGROUP:   //ungroup
			pOp = new opUngroup(this);
			break;

		case SelctedInfo:   //change selected info 
			pOp = new opChngSelInfo(this);
			break;

		case MOVE : 
			pOp = new opMove(this); // move by drag 
			break;
		//case LOAD:
		//	pOp = new Load(this);
		//	break;

		case SAVE:
			pOp = new opSave(this);
			break;

		case COPY:
			pOp = new Copy(this);
			break;

		case PASTE:
			pOp = new Paste(this);
			break;
	

			case DEL:
			pOp = new opdelete(this);
			break;


		case MULTISELECTION : 
			pOp = new MULTISELECT(this, multiSelect);
			break; 

		case SEND_BACK :
			pOp = new SendToBack(this);
			break;

		case DUPLICATED :
			pOp = new Duplicate(this);
			break;

		case EXIT:
			pOp = new Exit(this);
			break;

		
		case STATUS:	//a click on the status bar ==> no operation
			break;
	}

	return pOp;
	
}


void controller::SetClipboard(shape* clip) //To store the shape coppied in the clipboard
{
		Clipboard = clip;
}

shape* controller::GetClipboard()const
{
	return Clipboard;
}

void controller::setID(int Scount)
{
	ID = Scount;
}

//Add a shape to the list of shapes
void controller::AddShape(shape* pShp)
{
	if (Shpcount < MaxshapesCount)
	{
		shapesList[Shpcount] = pShp;
		shapesList[Shpcount++]->setID(++ID);
	}
}

int controller::getShpCount() const
{
	return Shpcount;
}

void controller::SendtoBack(shape* pShp)
{
	//Temporary pointer for swaping
	shape* temp;  
	if (pShp == shapesList[0])      //if it is the first shape
	{
		return;
	}
	for (int i = 1; i < Shpcount; i++)
	{
	
		if (shapesList[i] == pShp)
		{
			temp = shapesList[i];
			
			for (int j = i; j > 0; j--)
			{
				shapesList[j] = shapesList[j - 1];
			}
			shapesList[0] = temp;
			break;
		}
	}
}



//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all shapes on the user interface
void controller::UpdateInterface() const
{	
	pGraph->Draw(pGUI);
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the UI
GUI *controller::GetUI() const
{	return pGUI; }
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the Graph
Graph* controller::getGraph() const
{
	return pGraph;
}

//Destructor
controller::~controller()
{
	delete pGUI;
	delete pGraph;
	
}



//==================================================================================//
//							Run function											//
//==================================================================================//
void controller::Run()
{
	operationType OpType;
	do
	{
		/////////pWind->GetWindowSize(5, 5);
		//1. Ask the GUI to read the required operation from the user
		OpType = GetUseroperation();

		//2. Create an operation coresspondingly
		operation* pOpr = createOperation(OpType);
		 
		//3. Execute the created operation
		if (pOpr)
		{
			pOpr->Execute();//Execute
			delete pOpr;	//operation is not needed any more ==> delete it
			pOpr = nullptr;
		}

		//Update the interface
		UpdateInterface();

	} while (OpType != EXIT);

}

void controller::UnSelectFigures(int mul) const
{
	if (mul == 1 && multiSelect)
	{
		return;
	}
	for (int i = 0; i < Shpcount; i++)
	{
		shapesList[i]->SetSelected(false);
	}
};
