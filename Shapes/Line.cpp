#include "Line.h"
#include <fstream>
#include <string>
#include <iostream>
using namespace std;
Line::Line()
{

}
Line::Line(Point P1, Point P2, GfxInfo shapeGfxInfo):shape(shapeGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	Center.x = (Corner1.x + Corner2.x) / 2;
	Center.y = (Corner1.y + Corner2.y) / 2;
	Length= sqrt(pow(Corner1.x - Corner2.x, 2) + pow(Corner1.y - Corner2.y, 2));
}

Line::~Line()
{}

void Line::Save(ofstream& OutFile)
{


	OutFile << type << " " << Corner1.x << " " << Corner1.y << " " << Corner2.x << " " << Corner2.y << " " << (ShpGfxInfo.isFilled) << " " << to_string(ShpGfxInfo.FillClr.ucRed) << " " << to_string(ShpGfxInfo.FillClr.ucGreen) << " " << to_string(ShpGfxInfo.FillClr.ucBlue) << " " << to_string(ShpGfxInfo.DrawClr.ucRed) << " " << to_string(ShpGfxInfo.DrawClr.ucGreen) << " " << to_string(ShpGfxInfo.DrawClr.ucBlue) << " " << (ShpGfxInfo.BorderWdth) << endl;

}

void Line::Load(ifstream& Infile)
{
	string DrawColor;
	Infile >> ID >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y >> DrawColor;
	GfxInfo info;
	Infile >> info.isSelected;
	Infile >> info.DrawClr.ucBlue;
	Infile >> info.DrawClr.ucGreen;
	Infile >> info.DrawClr.ucRed;
}

void Line::Draw(GUI* pUI) const
{
	//Call Output::DrawLine to draw a line on the screen	
	pUI->DrawLn(Corner1, Corner2, ShpGfxInfo);

}

shape* Line::copy()
{
	shape* ptr = new Line (Corner1, Corner2, ShpGfxInfo);
	return ptr;
}

void Line::Move(Point P)
{

	// get dx and dy (d is the displacement)
	
	
	double dx = P.x - (Corner1.x + Corner2.x) / 2;
	double dy = P.y - (Corner1.y + Corner2.y) / 2;;
	// new corners 
	Corner1.x = Corner1.x + dx;
	Corner1.y = Corner1.y + dy;
	Corner2.x = Corner2.x + dx;
	Corner2.y = Corner2.y + dy;

}



shape* Line::Paste(Point p)
{
	Line* line = new  Line(Corner1, Corner2, ShpGfxInfo);

	Point oo;
	oo.x = (Corner1.x + Corner2.x) / 2;
	oo.y = (Corner1.y + Corner2.y) / 2;
	line->Corner1.x = p.x - oo.x + Corner1.x;
	line->Corner1.y = p.y - oo.y + Corner1.y;
	line->Corner2.x = p.x - oo.x + Corner2.x;
	line->Corner2.y = p.y - oo.y + Corner2.y;
	return line;
}

bool Line::point_included(int x, int y) {
	double slope = (Corner2.y - Corner1.y) / (Corner2.x - Corner1.x);
	double nslope = (y - Corner1.y) / (x - Corner2.x);
	if (nslope == slope || nslope == -slope) {
		return true;
	}
	else { return false; }
}

shape* Line::duplicate(GUI* pGUI) {
	Point p1, p2;
	p1.x = Corner1.x + 100;
	p1.y = Corner1.y;
	p2.x = Corner2.x + 100;
	p2.y = Corner2.y;
	GfxInfo info = ShpGfxInfo;
	ShpGfxInfo.isDuplicated = true;
	Line* L = new Line(p1, p2, info);
	return L;
}


void  Line::OPZOOM(double px, double py, double scale)  //function to zoom in or out according to the value of the scale factor
{
	Corner1.x = (Corner1.x * scale) - (scale * px) + px;
	Corner1.y = (Corner1.y * scale) - (scale * py) + py;
	Corner2.x = (Corner2.x * scale) - (scale * px) + px;
	Corner2.y = (Corner2.y * scale) - (scale * py) + py;
}
void Line::ResizeShape(double scale)  	//Resize a single line
{
	Length = scale * Length;
	Corner2.x = Corner1.x + Length;
	Corner2.y = Corner1.y + Length;
}
void Line::RotateShape()  	//Rotate a single line
{
	int C1x = Corner1.x;
	int C2x = Corner2.x;
	int C1y = Corner1.y;
	int C2y = Corner2.y;
	Corner1.x = Center.y + Center.x - C1y;
	Corner2.x = Center.y + Center.x - C2y;
	Corner1.y = C1x + Center.y - Center.x;
	Corner2.y = C2x + Center.y - Center.x;
}