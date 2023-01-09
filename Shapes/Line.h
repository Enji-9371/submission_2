#pragma once

#include "shape.h"

class Line : public shape
{
private:
	Point Corner1;
	Point Corner2;
	Point Center;
	int Length;
public:
	Line();
	Line(Point, Point, GfxInfo shapeGfxInfo);
	virtual ~Line();
	virtual bool point_included(int x, int y);
	virtual shape* copy();
	virtual void Save(ofstream& OutFile);
	virtual void Move(Point P);
	void Load(ifstream& Infile);
	virtual void Draw(GUI* pUI) const;
	virtual shape* Paste(Point);
	void OPZOOM(double px, double py, double scale);
	virtual shape* duplicate(GUI* pGUI);
	void ResizeShape(double scale);  	//Resize a single line
	void RotateShape();  	//Rotate a single line
};
