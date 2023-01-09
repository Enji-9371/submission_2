#pragma once
#include "shape.h"
#include<fstream>
class Ccircle : public shape
{private:
	Point center;
	Point border;
	Point Corner1; 
	Point Corner2;
	int rad;
public:

	Ccircle(Point, Point, GfxInfo shapeGfxInfo);
	
	
	virtual ~Ccircle();
	virtual bool point_included(int x, int y);
	virtual void Save(ofstream& OutFile);
	void Load(ifstream& Infile);
	virtual void Draw(GUI* pUI) const;
	virtual void Move(Point P);
	Ccircle(const Ccircle* copy);
	int* Getshapeinfo();
	virtual shape* clone();
	virtual shape* duplicate(GUI* pGUI);
	void OPZOOM(double px, double py, double scale);
	void ResizeShape(double scale);  	//Resize a single circle
	void RotateShape();  	//Rotate a single circle
	
};

