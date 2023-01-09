#pragma once

#include "shape.h"
#include <fstream>
class Rect : public shape
{
private:
	Point Corner1;	
	Point Corner2;
	Point Center;
public:
	Rect();
	Rect(Point , Point, GfxInfo shapeGfxInfo );
	virtual ~Rect();
	virtual void Save(ofstream& OutFile);
	void Load(ifstream& Infile);
	virtual shape* copy();
	virtual void Move(Point P);
	virtual shape* Paste(Point);
	virtual void Draw(GUI* pUI) const;
	virtual bool point_included(int z, int y);
	virtual shape* duplicate(GUI* pGUI);
	void OPZOOM(double px, double py, double scale);
	void ResizeShape(double scale);  	//Resize a single rectangle
	void RotateShape();  	//Rotate a single rectangle
};

