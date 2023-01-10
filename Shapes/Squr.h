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

	int* arrX = new int;
	int* arrY = new int;
public:
	Squr();
	Squr(Point, Point, GfxInfo shapeGfxInfo);
	virtual ~Squr();
	int get_id();
	void set_id(double n_id);
	virtual void Move(Point P);
	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& inFile);
	virtual void Draw(GUI* pUI) const;
	Squr(const Squr* copy);
	virtual shape* clone();
	virtual shape* duplicate(GUI* pGUI);
	int* Getshapeinfo();
	virtual bool point_included(int x, int y);
	void OPZOOM(double px, double py, double scale);
	void hideShape(GUI* pUI) override;
	void ResizeShape(double scale);  	//Resize a single square
	void RotateShape();  	//Rotate a single square
};