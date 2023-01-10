#pragma once
#include "..\CMUgraphicsLib\CMUgraphics.h"
#include"../CMUgraphicsLib/colors.h"
#include "..\Defs.h"

#include <string>
using namespace std;

struct Point	//To be used for shapes points
{
	int x, y;
};

struct GfxInfo	//Graphical info common for all shapes (you may add more members)
{
	color DrawClr;	//Draw color of the shape
	color FillClr;	//Fill color of the shape
	bool isFilled;	//shape Filled or not
	int BorderWdth;	//Width of shape borders
	bool isSelected;	//true if the shape is selected.
	bool isDuplicated;  //true if the shape is duplicated.
};




class GUI
{
	enum  Mmatch //enum for the output of  match function
	{
		MATCHED,
		NOT_MATCHED
	};

	enum GUI_MODE	//Graphical user interface mode
	{
		MODE_DRAW,	//Drawing mode (startup mode)
		MODE_PLAY,	//Playing mode
		MODE_PLT     //color palette mode
	};

	enum DrawMenuIcon //The icons of the Draw menu (you should add more icons)
	{
		//Note: Icons are ordered here as they appear in menu
		//If you want to change the menu icons order, change the order here
		ICON_RECT,
		ICON_LINE,
		ICON_SQUR,      //Square icon in menu
		ICON_ELLIP,     //Ellipse icon in menu
		ICON_RPOLY,
		ICON_REGPOLY,
		ICON_IRREGPOLY,  //Irregular Polygon icon in menu
		ICON_CIRC,	//Recangle icon in menu
		ICON_Ctriangle,
		ICON_SELINFO,    //change selected shape colors and width
		ICON_CLRPLT,     //color palette icon
		ICON_PNWDTH,      //pen width icon
		ICON_ROTATE,  //ROTATE A SHAPE
		ICON_RESIZE,   //RESIZE A SHAPE
		ICON_RESIZE_DRAG,  //resize by drag
		ICON_ZOOMIN,   //zoom in the whole screen
		ICON_ZOOMOUT,   //zoom out the whole screen
		ICON_GROUP,     //group shapes
		ICON_UNGROUP,    //ungroup shapes
		ICON_RESIZE_GROUP,  //resize a group of shapes

		ICON_LOAD,      // Load icon in menu
		ICON_SAVE,      // Save icon in menu
		ICON_MOVEBYDRAG,
		ICON_DELETE , 
		ICON_DUPLICATE,
		ICON_SELECT,
		ICON_MULTISELECTION,
		ICON_SENDTOBACK,
	
		ICON_COPY,
		ICON_PASTE,
		
		ICON_PLAY,      //Play mode icon in menu
		ICON_EXIT,		//Exit icon

		DRAW_ICON_COUNT		//no. of menu icons ==> This should be the last line in this enum

	};

	enum ClrPltMenuIcon //The icons of the Draw menu (you should add more icons)
	{
		//Note: Icons are ordered here as they appear in menu
		//If you want to change the menu icons order, change the order here
		ICON_Red,		//red color icon in menu
		ICON_Green,		//green color icon in menu
		ICON_Blue,		//blue color icon
		ICON_Yellow,		//yellow color icon
		ICON_Black,        //Black color icon

		Clr_ICON_COUNT		//no. of menu icons ==> This should be the last line in this enum

	};

	enum PlayMenuIcon //The icons of the Play menu (you should add more icons)
	{
		//Note: Icons are ordered here as they appear in menu
		//If you want to change the menu icons order, change the order here

		//TODO: Add more icons names here
		ICON_START,          //start game icon in menu
		ICON_MATCH,          //match icon in menu
		ICON_DRAW,          //Draw mode icon in menu
		PLAY_ICON_COUNT		//no. of menu icons ==> This should be the last line in this enum

	};


	GUI_MODE InterfaceMode;

	int	width, height,	//Window width and height
		wx, wy,			//Window starting coordinates
		StatusBarHeight,	//Status Bar Height
		ToolBarHeight,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		MenuIconWidth;		//Width of each icon in toolbar menu


	color DrawColor;		//Drawing color
	color FillColor;		//Filling color
	color HighlightColor;	//Highlighting color
	color MsgColor;			//Messages color
	color BkGrndColor;		//Background color
	color StatusBarColor;	//Status bar color
	int PenWidth;			//width of the pen that draws shapes
	bool IsFilled;          //filling status
	bool IsResized;          //resizing status
	/// Add more members if needed



	window* pWind;

public:

	GUI();

	// Input Functions  ---------------------------
	void GetPointClicked(int& x, int& y) const;//Get coordinate where user clicks
	
	
	window* DetectMouse();
	
	
	string GetSrting() const;	 //Returns a string entered by the user
	operationType GetUseroperation() const; //Read the user click and map to an operation

	// Output Functions  ---------------------------
	window* CreateWind(int, int, int, int) const; //creates the application window
	void CreateDrawToolBar();	//creates Draw mode toolbar & menu
	void CreatePlayToolBar();	//creates Play mode toolbar & menu
	void CreateStatusBar() const;	//create the status bar
	operationType CreateColorBar();          //create the new window of the colors

	void ClearStatusBar() const;	//Clears the status bar
	void ClearDrawArea() const;	//Clears the drawing area
	void ClearToolBar() const;  //Clears the tool bar

	// -- shapes Drawing functions
	void DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo) const;  //Draw a rectangle
	void DrawTriangle(Point P1, Point P2, Point P3 ,GfxInfo CtriangleGfxInfo) const;  //Draw a triangle
	void DrawCircle(Point p1, double x, GfxInfo CcircleGfxInfo) const; //draw circle 
	void DrawLn(Point P1, Point P2, GfxInfo LnGfxInfo) const;  //Draw a line

	void DrawSqur(Point P1, Point P2, GfxInfo SqurGfxInfo) const; //Draw a square

	void DrawEllip(Point P1, Point P2, GfxInfo EllipGfxInfo) const;  //Draw an ellipse

	void DrawPolygon(int* A_X, int* A_Y, int num, GfxInfo PolygonGfxInfo) const;   //Draw an Irregular polygon

	///Make similar functions for drawing all other shapes.

	
	///Make similar functions for drawing all other shapes.
	//void DrawTriangle(const int iX1, const int iY1, const int iX2, const int iY2, const int iX3, const int iY3, const drawstyle dsStyle = FILLED);
	
	void PrintMessage(string msg) const;	//Print a message on Status bar

	color getCrntDrawColor() const;	//get current drwawing color
	color getCrntFillColor() const;	//get current filling color
	int getCrntPenWidth() const;		//get current pen width
	bool GetIsFilled()const;
	void setCrntDrawColor(operationType dcolor);	//set current drawing color
	void setCrntFillColor(operationType fcolor);	//set current filling color
	void setCrntPenWidth(int width);		//set current pen width
	bool SetResized(); //set resized
	~GUI();
};

