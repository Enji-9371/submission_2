#pragma once

#include "shape.h"

class Ellip : public shape
{
private:
	Point Corner1;
	Point Corner2;
	Point Center;
public:
	Ellip();
	Ellip (Point, Point, GfxInfo shapeGfxInfo);
	virtual ~Ellip();
	void Save(ofstream& OutFile);
	void Load(ifstream& Infile);
	virtual shape* copy();
	virtual bool point_included(int x, int y);
	virtual shape* duplicate(GUI* pGUI);
	virtual void Draw(GUI* pUI) const;
	virtual shape* Paste(Point);
	virtual void Move(Point P);
	void OPZOOM(double px, double py, double scale);
	void ResizeShape(double scale);  	//Resize a single ellipse
	void RotateShape();  	//Rotate a single ellipse
};