#include "GUI.h"
#include <iostream>
GUI::GUI()
{
	//Initialize user interface parameters
	InterfaceMode = MODE_DRAW;

	width = 1500;
	height = 750;
	wx = 5;
	wy = 5;
	StatusBarHeight = 50;
	ToolBarHeight = 50;
	MenuIconWidth = 40;

	DrawColor = BLACK;	//default Drawing color
	FillColor = GREEN;	//default Filling color
	MsgColor = BLACK;		//Messages color
	BkGrndColor = LIGHTPINK;	//Background color
	IsFilled = false;  //default is not filled
	HighlightColor = MAGENTA;	//This color should NOT be used to draw shapes. use if for highlight only
	StatusBarColor = WHITE;
	PenWidth = 3;	//default width of the shapes frames
	//Create the output window
	pWind = CreateWind(width, height, wx, wy);
	//Change the title
	pWind->ChangeTitle("- - - - - - - - - - PAINT ^ ^ PLAY - - - - - - - - - -");
	CreateDrawToolBar();
	CreateStatusBar();
}

bool GUI::GetIsFilled()const  //get current fill status
{
	return IsFilled;
}



//======================================================================================//
//								Input Functions										//
//======================================================================================//
void GUI::GetPointClicked(int& x, int& y) const
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}
window* GUI::DetectMouse()
{
	return this->pWind;
}

string GUI::GetSrting() const
{
	string Label;
	char Key;
	keytype ktype;
	pWind->FlushKeyQueue();
	while (1)
	{
		ktype = pWind->WaitKeyPress(Key);
		if (ktype == ESCAPE )	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if (Key == 13)	//ENTER key is pressed
			return Label;
		if (Key == 8)	//BackSpace is pressed
			if( Label.size() > 0)	
				Label.resize(Label.size() - 1);
			else
				Key = '\0';		
		else
			Label += Key;
		PrintMessage(Label);
	}
}

//This function reads the position where the user clicks to determine the desired operation
operationType GUI::GetUseroperation() const
{
	int x, y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if (InterfaceMode == MODE_DRAW)	//GUI in the DRAW mode
	{
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < ToolBarHeight)
		{
			//Check whick Menu icon was clicked
			//==> This assumes that menu icons are lined up horizontally <==
			int ClickedIconOrder = (x / MenuIconWidth);
			//Divide x coord of the point clicked by the menu icon width (int division)
			//if division result is 0 ==> first icon is clicked, if 1 ==> 2nd icon and so on

			switch (ClickedIconOrder)
			{
			case ICON_RECT: return DRAW_RECT; break;
			case ICON_CIRC: return DRAW_CIRC;  break;
			case ICON_LINE: return DRAW_LINE;  break;
			case ICON_Ctriangle: return DRAW_TRI;  break;
			case ICON_REGPOLY: return DRAW_REGPOLY;  break;
			case ICON_EXIT: return EXIT;  break;
			case ICON_RPOLY: return DRAW_RPOLY;  break;
			case ICON_SQUR: return DRAW_SQUR;  break;
			case ICON_ELLIP: return DRAW_ELLIP;  break;
			case ICON_IRREGPOLY: return DRAW_IRREGPOLY;  break;
			case ICON_CLRPLT: return COLOR_PALETTE;  break;
			case ICON_PNWDTH: return PEN_WIDTH; break;
			case ICON_ROTATE: return ROTATE;  break;
			case ICON_RESIZE: return RESIZE;  break;
			case ICON_ZOOMIN: return ZOOM_IN;  break;
			case ICON_ZOOMOUT: return ZOOM_OUT;  break;
			case ICON_GROUP: return GROUP;  break;
			case ICON_UNGROUP: return UNGROUP;  break;
			case ICON_PLAY: return TO_PLAY;  break;
			case ICON_LOAD: return LOAD;  break;
			case ICON_SAVE: return SAVE;  break;
			case ICON_SELECT: return SELECT; break;
			case ICON_COPY: return COPY; break;
			case ICON_PASTE: return PASTE;  break;
			case ICON_MULTISELECTION: return MULTISELECTION;  break;
			case ICON_MOVEBYDRAG: return MOVE; break;
			case ICON_SELINFO: return SelctedInfo;  break;
			case ICON_SENDTOBACK: return SEND_BACK;  break;
			case  ICON_DELETE: return DEL;  break;
			case ICON_DUPLICATE: return DUPLICATED;  break;
			case ICON_SIMAGE: return STICK; break;
			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if (y >= ToolBarHeight && y < height - StatusBarHeight)
		{
			return DRAWING_AREA;
		}

		//[3] User clicks on the status bar
		return STATUS;
	}
	else	//GUI is in PLAY mode
	{
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < ToolBarHeight)
		{
			//Check whick Menu icon was clicked
			//==> This assumes that menu icons are lined up horizontally <==
			int ClickedIconOrder = (x / MenuIconWidth);
			//Divide x coord of the point clicked by the menu icon width (int division)
			//if division result is 0 ==> first icon is clicked, if 1 ==> 2nd icon and so on

			switch (ClickedIconOrder)
			{
			case ICON_DRAW: return TO_DRAW; break;
			case ICON_MATCH: return MATCH;  break;
			case ICON_START: return START;  break;

			default: return EMPTY; break;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if (y >= ToolBarHeight && y < height - StatusBarHeight)
		{
			return DRAWING_AREA;
		}

		//[2] User clicks on the status bar
		return STATUS;
	}
	///TODO:
	//perform checks similar to Draw mode checks above
	//and return the correspoding operation
	return TO_PLAY;	//just for now. This should be updated
}
////////////////////////////////////////////////////



//======================================================================================//
//								Output Functions										//
//======================================================================================//




//___________________________________________________________________________
window* GUI::CreateWind(int w, int h, int x, int y) const
{
	window* pW = new window(w, h, x, y);
	pW->SetBrush(BkGrndColor);
	pW->SetPen(BkGrndColor, 1);
	pW->DrawRectangle(0, ToolBarHeight, w, h);
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void GUI::CreateStatusBar() const
{
	pWind->SetPen(StatusBarColor, 1);
	pWind->SetBrush(StatusBarColor);
	pWind->DrawRectangle(0, height - StatusBarHeight, width, height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void GUI::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(StatusBarColor, 1);
	pWind->SetBrush(StatusBarColor);
	pWind->DrawRectangle(0, height - StatusBarHeight, width, height);

}
//////////////////////////////////////////////////////////////////////////////////////////
void GUI::CreateDrawToolBar() 
{
	InterfaceMode = MODE_DRAW;

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way

	//First prepare List of images for each menu icon
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuIcon
	string MenuIconImages[DRAW_ICON_COUNT];
	MenuIconImages[ICON_RECT] = "images\\MenuIcons\\Menu_Rect.jpg";
	MenuIconImages[ICON_CIRC] = "images\\MenuIcons\\Menu_Circ.jpg";
	MenuIconImages[ICON_Ctriangle] = "images\\MenuIcons\\treiangle.jpg";
	MenuIconImages[ICON_REGPOLY ] = "images\\MenuIcons\\irregular.jpg";
	MenuIconImages[ICON_EXIT] = "images\\MenuIcons\\Menu_Exit.jpg";
	MenuIconImages[ICON_RPOLY] = "images\\MenuIcons\\Menu_REGPOLY.jpg";
	MenuIconImages[ICON_LINE] = "images\\MenuIcons\\Menu_Line.jpg";
	MenuIconImages[ICON_SQUR] = "images\\MenuIcons\\Menu_Squr.jpg";
	MenuIconImages[ICON_ELLIP] = "images\\MenuIcons\\Menu_Ellip.jpg";
	MenuIconImages[ICON_IRREGPOLY] = "images\\MenuIcons\\Menu_IrregPoly.jpg";
	MenuIconImages[ICON_CLRPLT] = "images\\MenuIcons\\Menu_ClrPlt.jpg";
	MenuIconImages[ICON_PNWDTH] = "images\\MenuIcons\\Menu_Width.jpg";
	MenuIconImages[ICON_PLAY] = "images\\MenuIcons\\Menu_SwitchToPlay.jpg";
	MenuIconImages[ICON_LOAD] = "images\\MenuIcons\\Menu_Load.jpg";
	MenuIconImages[ICON_SAVE] = "images\\MenuIcons\\SAVE.jpg";
	MenuIconImages[ICON_ROTATE] = "images\\MenuIcons\\Rotate.jpg";
	MenuIconImages[ICON_RESIZE] = "images\\MenuIcons\\Resize.jpg";
	MenuIconImages[ICON_RESIZE_DRAG] = "images\\MenuIcons\\ResizeByDrag.jpg";
	MenuIconImages[ICON_ZOOMIN] = "images\\MenuIcons\\ZoomIn.jpg";
	MenuIconImages[ICON_ZOOMOUT] = "images\\MenuIcons\\ZoomOut.jpg";
	MenuIconImages[ICON_GROUP] = "images\\MenuIcons\\Group.jpg";
	MenuIconImages[ICON_UNGROUP] = "images\\MenuIcons\\Ungroup.jpg";
	MenuIconImages[ICON_RESIZE_GROUP] = "images\\MenuIcons\\Resize_Group.jpg";
	MenuIconImages[ICON_SELECT ] = "images\\MenuIcons\\select.jpg";
	MenuIconImages[ICON_COPY] = "images\\MenuIcons\\copy.jpg";
	MenuIconImages[ICON_PASTE] = "images\\MenuIcons\\paste.jpg";
	MenuIconImages[ICON_MULTISELECTION] = "images\\MenuIcons\\MULTISELECTION.jpg";
	MenuIconImages[ICON_MOVEBYDRAG] = "images\\MenuIcons\\MOVE.jpg";
	MenuIconImages[ICON_SELINFO] = "images\\MenuIcons\\SelInfo.jpg";
	MenuIconImages[ICON_SENDTOBACK] = "images\\MenuIcons\\sendtoback.jpg";
	MenuIconImages[ICON_DUPLICATE] = "images\\MenuIcons\\duplicate.jpg";
	MenuIconImages[ICON_DELETE] = "images\\MenuIcons\\DELETE.jpg";
	MenuIconImages[ICON_SIMAGE] = "images\\MenuIcons\\image.jpg";

	//TODO: Prepare images for each menu icon and add it to the list

	//Draw menu icon one image at a time
	for (int i = 0; i < DRAW_ICON_COUNT; i++)
		pWind->DrawImage(MenuIconImages[i], i * MenuIconWidth, 0,MenuIconWidth, ToolBarHeight );



	//Draw a line under the toolbar
	pWind->SetPen(BLACK, 3);
	pWind->DrawLine(0, ToolBarHeight, width, ToolBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////

operationType GUI::CreateColorBar()
{
	
	InterfaceMode = MODE_PLT; //set interfacemode to the color bar mode 
	int x, y;
	string MenuIconImages[Clr_ICON_COUNT];
	MenuIconImages[ICON_Red] = "images\\MenuIcons\\Red.jpg";
	MenuIconImages[ICON_Green] = "images\\MenuIcons\\Green.jpg";
	MenuIconImages[ICON_Blue] = "images\\MenuIcons\\Blue.jpg";
	MenuIconImages[ICON_Yellow] = "images\\MenuIcons\\Yellow.jpg";
	MenuIconImages[ICON_Black] = "images\\MenuIcons\\Black.jpg";
	PrintMessage("Press 'D' to Change The General Drawing Color, 'F' to Chang The General Filling Color : ");
	string choice = GetSrting();  //get the input 

	if (choice == "d" || choice == "D") //if this case is true, user wants to change draw color
	{
		ClearStatusBar(); //clear the status bar
		ClearToolBar();   //clear the tool bar
		PrintMessage("Now Choose a Color: ");
		//Draw menu icon one image at a time
		for (int i = 0; i < Clr_ICON_COUNT; i++)
			pWind->DrawImage(MenuIconImages[i], i * MenuIconWidth, 0, MenuIconWidth, ToolBarHeight);
		//[1] If user clicks on the Toolbar
		pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click
		if (y >= 0 && y < ToolBarHeight)
		{
			ClearStatusBar();   //clear the status bar
			int ClickedIconOrder = (x / MenuIconWidth);
			//Divide x coord of the point clicked by the menu icon width (int division)
			//if division result is 0 ==> first icon is clicked, if 1 ==> 2nd icon and so on

			switch (ClickedIconOrder) //return enum to determine which draw color is chosen
			{
			case ICON_Red: { return dChangeToRed; break; }
			case ICON_Green: { return dChangeToGreen; break; }
			case ICON_Blue: {return dChangeToBlue; break; }
			case ICON_Yellow: { return dChangeToYellow; break; }
			case ICON_Black: {return dChangeToBlack; break; }
			default: {return EMPTY; break; }	//A click on empty place in desgin toolbar
			}
		}
	}
	else if (choice == "f" || choice == "F") //if this case is true, user wants to change fill color
	{
		ClearStatusBar(); //clear the status bar
		ClearToolBar();  //clear the tool bar
		PrintMessage("Now Choose a Color: ");
		//Draw menu icon one image at a time
		for (int i = 0; i < Clr_ICON_COUNT; i++)
			pWind->DrawImage(MenuIconImages[i], i * MenuIconWidth, 0, MenuIconWidth, ToolBarHeight);
		//[1] If user clicks on the Toolbar
		pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click
		if (y >= 0 && y < ToolBarHeight)
		{
			ClearStatusBar();  //clear the status bar 
			int ClickedIconOrder = (x / MenuIconWidth);
			//Divide x coord of the point clicked by the menu icon width (int division)
			//if division result is 0 ==> first icon is clicked, if 1 ==> 2nd icon and so on

			switch (ClickedIconOrder) //return enum to determine which fill color is chosen
			{
			case ICON_Red: {return fChangeToRed; break; }
			case ICON_Green: { return fChangeToGreen; break; }
			case ICON_Blue: {return fChangeToBlue; break; }
			case ICON_Yellow: { return fChangeToYellow; break; }
			case ICON_Black: { return fChangeToBlack; break; }
			default: {return EMPTY; break; }	//A click on empty place in desgin toolbar
			}
		}
	}
	else
	{
		PrintMessage("Unsupportted Operation!"); //if input is out of range
		return EMPTY;
	}
}


void GUI::CreatePlayToolBar() 
{
	int  play_width = 1800;
	int play_ToolBarHeight = 47;
	int play_MenuIconWidth = 60;

	InterfaceMode = MODE_PLAY;
	string MenuIconImages[PLAY_ICON_COUNT];

	MenuIconImages[ICON_DRAW] = "images\\MenuIcons\\Menu_SwitchToDraw.jpg";
	MenuIconImages[ICON_MATCH] = "images\\MenuIcons\\match.jpg";
	MenuIconImages[ICON_START] = "images\\MenuIcons\\start.jpg";



	//TODO: Prepare images for each menu icon and add it to the list

	//Draw menu icon one image at a time
	for (int i = 0; i < PLAY_ICON_COUNT; i++)
		pWind->DrawImage(MenuIconImages[i], i * play_MenuIconWidth, 0, play_MenuIconWidth, play_ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(BLACK, 3);
	pWind->DrawLine(0, play_ToolBarHeight, play_width, play_ToolBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////

void GUI::ClearDrawArea() const
{
	pWind->SetPen(BkGrndColor, 1);
	pWind->SetBrush(BkGrndColor);
	pWind->DrawRectangle(0, ToolBarHeight, width, height - StatusBarHeight);

}


void GUI::ClearToolBar() const
{
	pWind->SetPen(BkGrndColor, 1);
	pWind->SetBrush(BkGrndColor);
	pWind->DrawRectangle(0, 0, width, ToolBarHeight);

}

//////////////////////////////////////////////////////////////////////////////////////////

void GUI::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar

	pWind->SetPen(MsgColor, 50);
	pWind->SetFont(24, BOLD, BY_NAME, "Arial");
	pWind->DrawString(10, height - (int)(0.75 * StatusBarHeight), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////

color GUI::getCrntDrawColor() const	//get current drwawing color
{
	return DrawColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

color GUI::getCrntFillColor() const	//get current filling color
{
	return FillColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

int GUI::getCrntPenWidth() const		//get current pen width
{
	return PenWidth;
}
//======================================================================================//
//						draw_fill colors & width setters(general shapes)	        	//
//======================================================================================//

void GUI::setCrntDrawColor(operationType dcolor)   //set current general drawing color            
{
	switch (dcolor)
	{
	case dChangeToRed: DrawColor = RED; break;   //set the draw color according to the enum(operationtype) returned from the function CreateColorBar()
	case dChangeToGreen: DrawColor = GREEN; break;
	case dChangeToBlack: DrawColor = BLACK; break;
	case dChangeToBlue: DrawColor = BLUE; break;
	case dChangeToYellow: DrawColor = YELLOW; break;
	}
}

void GUI::setCrntFillColor(operationType fcolor) 	//set current general filling color
{
	IsFilled = true;
	switch (fcolor)
	{
	case fChangeToRed:FillColor = RED; break;  //set the fill color according to the enum(operationtype) returned from the function CreateColorBar()
	case fChangeToGreen: FillColor = GREEN; break;
	case fChangeToBlack:FillColor = BLACK; break;
	case fChangeToBlue:FillColor = BLUE; break;
	case fChangeToYellow: FillColor = YELLOW; break;
	}
}

void GUI::setCrntPenWidth(int width) 		//set current general pen width
{
	PenWidth = width;  //set the pen width according to the enum(operationtype) returned from the function CreateColorBar()
}





//======================================================================================//
//								shapes Drawing Functions								//
//======================================================================================//


void GUI::DrawLn(Point P1, Point P2, GfxInfo LnGfxInfo) const
{
	color DrawingClr;
	if (LnGfxInfo.isSelected)	//shape is selected
		DrawingClr = HighlightColor; //shape should be drawn highlighted
	else
		DrawingClr = LnGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, LnGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (LnGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(LnGfxInfo.FillClr);
	}
	else
		style = FRAME;

	pWind->DrawLine(P1.x, P1.y, P2.x, P2.y, style);

}

void GUI::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo) const
{
	color DrawingClr;
	if (RectGfxInfo.isSelected)	//shape is selected
		DrawingClr = HighlightColor; //shape should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;
pWind->SetPen(DrawingClr, RectGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;

	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);


}

void GUI::DrawSqur(Point P1, Point P2, GfxInfo SqurGfxInfo) const
{
	color DrawingClr;
	if (SqurGfxInfo.isSelected)	//shape is selected
		DrawingClr = HighlightColor; //shape should be drawn highlighted
	else
		DrawingClr = SqurGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, SqurGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (SqurGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(SqurGfxInfo.FillClr);
	}
	else
		style = FRAME;

	pWind->DrawSquare(P1.x, P1.y, P2.x, P2.y, style);
}

void GUI::DrawEllip(Point P1, Point P2, GfxInfo EllipGfxInfo) const
{
	color DrawingClr;
	if (EllipGfxInfo.isSelected)	//shape is selected
		DrawingClr = HighlightColor; //shape should be drawn highlighted
	else
		DrawingClr = EllipGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, EllipGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (EllipGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(EllipGfxInfo.FillClr);
	}
	else
		style = FRAME;

	pWind->DrawEllipse(P1.x, P1.y, P2.x, P2.y, style);

}

void GUI::StickImage(string photo, int x, int y, int width, int height) const
{
	pWind->DrawImage(photo, x, y, width, height);

}

///////////////////////////////////////////////
void GUI::DrawTriangle(Point P1, Point P2, Point P3, GfxInfo CtriangleGfxInfo) const
{
	color DrawingClr;
	if (CtriangleGfxInfo.isSelected)	//shape is selected
		DrawingClr = HighlightColor; //shape should be drawn highlighted
	else
		DrawingClr = CtriangleGfxInfo.DrawClr;
	pWind->SetPen(DrawingClr, CtriangleGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (CtriangleGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(CtriangleGfxInfo.FillClr);
	}
	else
		style = FRAME;

	pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y, style);

}

////////////////////////////////////////////////////////////////////////////
void GUI::DrawCircle(Point P1, double rad, GfxInfo circlefxInfo) const
{
	color DrawingClr;
	if (circlefxInfo.isSelected)	//shape is selected
		DrawingClr = HighlightColor; //shape should be drawn highlighted
	else
		DrawingClr = circlefxInfo.DrawClr;
	pWind->SetPen(DrawingClr, circlefxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (circlefxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(circlefxInfo.FillClr);
	}
	else
		style = FRAME;

	pWind->DrawCircle(P1.x, P1.y, rad, style);
}



void GUI::DrawPolygon(int* A_X, int* A_Y, int num, GfxInfo PolygonGfxInfo) const
{
	color DrawingClr;
	if (PolygonGfxInfo.isSelected)	//shape is selected
		DrawingClr = HighlightColor; //shape should be drawn highlighted
	else
		DrawingClr = PolygonGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, PolygonGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (PolygonGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(PolygonGfxInfo.FillClr);
	}
	else
		style = FRAME;

	pWind->DrawPolygon(A_X,A_Y ,num, style);

}

/////////////////////////////////////////////////////////////////////////////////////////
GUI::~GUI()
{
	delete pWind;
}

//__________________________________________________________________________________________

bool GUI::SetResized()
{
	IsResized = true;
	return IsResized;
}