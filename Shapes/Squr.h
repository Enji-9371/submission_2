#pragma once

#include "shape.h"

class Squr : public shape
{
private:
	Point Corner1;
	Point Corner2;
	Point center;
	double L;
	double id;

public:
	Squr();
	Squr(Point, Point, GfxInfo shapeGfxInfo);
	virtual ~Squr();
	int get_id();
	void set_id(double n_id);
	virtual void Move(Point P);
	virtual void Save(ofstream& OutFile);
	void Load(ifstream& Infile);
	virtual void Draw(GUI* pUI) const;
	virtual shape* copy();
	virtual shape* Paste(Point);
	virtual shape* duplicate(GUI* pGUI);
	virtual bool point_included(int x, int y);
	void OPZOOM(double px, double py, double scale);
	void ResizeShape(double scale);  	//Resize a single square
	void RotateShape();  	//Rotate a single square
};