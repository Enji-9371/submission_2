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
	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& inFile);
	virtual void Move(Point P);
	int* Getshapeinfo();
	virtual void Draw(GUI* pUI) const;
	void OPZOOM(double px, double py, double scale);
	Line(const Line* copy);
	virtual shape* clone();
	virtual shape* duplicate(GUI* pGUI);
	void ResizeShape(double scale);  	//Resize a single line
	void RotateShape();  	//Rotate a single line
};
