#pragma once
#include "Shape.h"
class polygon : public shape
{
private:
	Point center;
	Point point1;
	int num = 0;
	double distance;
	int* arrayX = new int[num];
	int* arrayY = new int[num];
	int* x = nullptr;
	int* y = nullptr;

public:
	polygon();
	polygon(Point, Point, int, GfxInfo shapeGfxInfo);
	virtual ~polygon();
	virtual void Draw(GUI* pUI) const;
	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& Outfile);
	virtual shape* duplicate(GUI* pGUI);
	polygon(const polygon* copy);
	virtual shape* clone();
	virtual void Move(Point P);
	virtual bool point_included(int x, int y);
	int* Getshapeinfo();
	void OPZOOM(double px, double py, double scale);
	void ResizeShape(double scale);  	//Resize a single ellipse
	void RotateShape();  	//Rotate a single ellipse

};