#pragma once
#include "..\defs.h"
#include "..\GUI\GUI.h"


//Base class for all shapes
class shape
{
protected:
	int ID;		//Each shape has an ID
	GfxInfo ShpGfxInfo;	//shape graphis info
	shape* pntr;
	shape* pntrr;
	/// Add more parameters if needed.

public:
    shape();
	string type; 
	shape(GfxInfo shapeGfxInfo);
	virtual ~shape() {}
	void SetSelected(bool s);	//select/unselect the shape
	bool IsSelected() const;	//check whether fig is selected
	bool IsDuplicated() const;  //check whether the shape is duplicated or not
	void IsHidden(bool h);
	bool IsSticked = false;


	virtual void Draw(GUI* pUI) const  = 0 ;		//Draw the shape

	int getID() const;
	void setID(int);

	shape* pshp;
	void ChngDrawClr(color Dclr);	//changes the shape's drawing color
	void ChngFillClr(color Fclr);	//changes the shape's filling color
	void ChngDrawWidth(int Wnum);
	///The following functions should be supported by the shape class
	///It should be overridden by each inherited shape

	///Decide the parameters that you should pass to each function	
	virtual bool point_included(int x, int y) = 0;
	virtual void Save(ofstream &OutFile) = 0;	//Save the shape parameters to the file
	virtual void Load(ifstream &Infile) = 0;	//Load the shape parameters to the file
	virtual shape* duplicate(GUI* pGUI) = 0;
	virtual void Move(Point P) = 0;	//move 
	virtual shape* clone() = 0;
	virtual int* Getshapeinfo() = 0;

	virtual void OPZOOM(double x, double y, double scale) = 0;   //virtual func. to zoom all shapes
	virtual void ResizeShape(double scale) = 0;  	//Resize a single shape
	virtual void RotateShape() = 0;  	//Rotate a single shape
	
};

//double Fcaldistance(Point x ,Point y); 
