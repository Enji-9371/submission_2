#pragma once

#include "shape.h"

class Ellip : public shape
{
private:
	Point Corner1;
	Point Corner2;
	Point Center;
	int Distance;
public:
	Ellip();
	Ellip (Point, Point, GfxInfo shapeGfxInfo);
	virtual ~Ellip();
	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& Outfile);
	virtual bool point_included(int x, int y);
	virtual shape* duplicate(GUI* pGUI);
	Ellip(const Ellip* copy);
	virtual shape* clone();
	virtual void Draw(GUI* pUI) const;
	int* Getshapeinfo();
	void hideShape(GUI* pUI) override;
	virtual void Move(Point P);
	void OPZOOM(double px, double py, double scale);
	void ResizeShape(double scale);  	//Resize a single ellipse
	void RotateShape();  	//Rotate a single ellipse
	void Scramble(int i, int j);
};