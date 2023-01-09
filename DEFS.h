#ifndef DEFS_H
#define DEFS_H


//This file contais some global constants and definitions to be used in the project.
enum operationType //The operations supported (you can add more if needed)
{
	DRAW_LINE,		//Draw Line
	DRAW_RECT,		//Draw Rectangle
	DRAW_TRI,		//Draw Triangle
	DRAW_CIRC,        //Draw Circle
	DRAW_REGPOLY,// draw requalr polygon 
	DRAW_RPOLY , 
	DRAW_SQUR,      //Draw Square
	DRAW_ELLIP,     //Draw Ellipse
	DRAW_IRREGPOLY, //Draw Irregular Polygon
	CHNG_DRAW_CLR,	//Change the drawing color
	CHNG_FILL_CLR,	//Change the filling color
	CHNG_BK_CLR,	//Change background color
	DEL,			//Delete a shape(s)
	MOVE,			//Move a shape(s)
	RESIZE,			//Resize a shape(s)
	ROTATE,			//Rotate a shape(s)
	SEND_BACK,		//Send a shape to the back of all shapes
	BRNG_FRNT,		//Bring a shape to the front of all shapes
	SAVE,			//Save the whole graph to a file
	LOAD,			//Load a graph from a file
	EXIT,			//Exit the application
    MULTISELECTION , 
	dChangeToRed,    //change current draw color to red
	dChangeToGreen,   //change current draw color to green
	dChangeToBlack,   //change current draw color to black
	dChangeToBlue,  //change current draw color to blue
	dChangeToYellow,   //change current draw color to yellow

	fChangeToRed,    //change current fill color to red
	fChangeToGreen,   //change current fill color to green
	fChangeToBlack,   //change current fill color to black
	fChangeToBlue,  //change current fill color to blue
	fChangeToYellow,   //change current fill color to yellow
	DRAWING_AREA,	//A click on the drawing area
	STATUS,			//A click on the status bar
	EMPTY,			//A click on empty place in the toolbar
	COLOR_PALETTE,  //offer the user color options
	PEN_WIDTH,      //enum to pen width operation

	TO_PLAY,		//Switch interface to Play mode
	ZOOM_IN ,      //zoom in
	ZOOM_OUT,      //zoom out
	SelctedInfo,
	GROUP,         //group
	UNGROUP ,       //ungroup
	COPY,           //copy
	PASTE,          //paste
	SELECT,
	DUPLICATED,
	TO_DRAW,
	MATCH,
	START,
	///TODO: Add more operation types (if needed)
};

enum Shapes
{
	_Rectangle,
	_Line,
	_Square,
	_IrrPoly,
	_Ellipse,
};


#endif