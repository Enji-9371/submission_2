#pragma once

#include "shape.h"

class Squr : public shape
{
private:
	Point Corner1;
	Point Corner2;
	Point center;
	double L;
public:
	Squr();
	Squr(Point, Point, GfxInfo shapeGfxInfo);
	virtual ~Squr();
	virtual void Move(Point P);
	virtual void Save(ofstream& OutFile);
	void Load(ifstream& Infile);
	virtual void Draw(GUI* pUI) const;
	Squr(const Squr* copy);
	virtual shape* clone();
	virtual shape* duplicate(GUI* pGUI);
	int* Getshapeinfo();
	virtual bool point_included(int x, int y);
	void OPZOOM(double px, double py, double scale);
	void ResizeShape(double scale);  	//Resize a single square
	void RotateShape();  	//Rotate a single square
};