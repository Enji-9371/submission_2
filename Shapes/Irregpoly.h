#pragma once
#include "Shape.h"
#include <fstream>

class irr_polygon :public shape
{

private:
	Point* array_points;
	Point Center;
	int num = 0;  //number of vertices 
	int* Array_X = new int[num];
	int* Array_Y = new int[num];
	int* x = nullptr;
	int* y = nullptr;

public:
	irr_polygon();
	irr_polygon(Point*, int, GfxInfo shapeGfxInfo);
	virtual ~irr_polygon();
	void Save(ofstream& OutFile);
	void Load(ifstream& Infile);
	virtual void Draw(GUI* pUI) const;
	virtual void Move(Point P);
	virtual shape* duplicate(GUI* pGUI);
	virtual shape* clone();
	void hideShape(GUI* pUI);
	int* Getshapeinfo();
	virtual bool point_included(int x, int y);
	void OPZOOM(double px, double py, double scale);
	void ResizeShape(double scale);  	//Resize a single ellipse
	void RotateShape();  	//Rotate a single ellipse
	void Scramble(int i, int j);

};

