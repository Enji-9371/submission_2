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

int* Line::Getshapeinfo()
{
	int dis = Length;
	int list[4];
	if (Corner1.x < Corner2.x && Corner1.y > Corner2.y) {
		list[0] = Corner1.x - 10;
		list[1] = Corner2.y - 10;
		list[2] = dis + 20;
		list[3] = dis + 20;
		return list;
	}
	else if (Corner1.x < Corner2.x && Corner1.y < Corner2.y) {
		list[0] = Corner1.x - 10;
		list[1] = Corner1.y - 10;
		list[2] = dis + 20;
		list[3] = dis + 20;
		return list;
	}
	else if (Corner1.x > Corner2.x && Corner1.y > Corner2.y) {
		list[0] = Corner2.x - 10;
		list[1] = Corner2.y - 10;
		list[2] = dis + 20;
		list[3] = dis + 20;
		return list;
	}
	else if (Corner1.x > Corner2.x && Corner1.y < Corner2.y) {
		list[0] = Corner2.x - 10;
		list[1] = Corner1.y - 10;
		list[2] = dis + 20;
		list[3] = dis + 20;
		return list;
	}
}

void Line::Save(ofstream& OutFile)
{


	OutFile << type << " " << Corner1.x << " " << Corner1.y << " " << Corner2.x << " " << Corner2.y << " " << (ShpGfxInfo.isFilled) << " " << to_string(ShpGfxInfo.FillClr.ucRed) << " " << to_string(ShpGfxInfo.FillClr.ucGreen) << " " << to_string(ShpGfxInfo.FillClr.ucBlue) << " " << to_string(ShpGfxInfo.DrawClr.ucRed) << " " << to_string(ShpGfxInfo.DrawClr.ucGreen) << " " << to_string(ShpGfxInfo.DrawClr.ucBlue) << " " << (ShpGfxInfo.BorderWdth) << endl;

}

void Line::Load(ifstream& inFile)
{
	type = "line";
	int x;
	string jump;

	inFile >> x;
	Corner1.x = x;

	inFile >> x;
	Corner1.y = x;

	inFile >> x;

	Corner2.x = x;

	inFile >> x;
	Corner2.y = x;

	inFile >> x;
	if (x == 0)
	{
		ShpGfxInfo.isFilled = FALSE;

	}
	else if (x == 1)
	{
		ShpGfxInfo.isFilled = TRUE;

	}
	inFile >> jump;

	ShpGfxInfo.FillClr.ucRed = stoi(jump);
	inFile >> jump;

	ShpGfxInfo.FillClr.ucGreen = stoi(jump);
	inFile >> jump;

	ShpGfxInfo.FillClr.ucBlue = stoi(jump);
	inFile >> jump;

	ShpGfxInfo.DrawClr.ucRed = stoi(jump);
	inFile >> jump;

	ShpGfxInfo.DrawClr.ucGreen = stoi(jump);
	inFile >> jump;

	ShpGfxInfo.DrawClr.ucBlue = stoi(jump);
	inFile >> x;

	ShpGfxInfo.BorderWdth = x;

	ShpGfxInfo.isSelected = FALSE;
}


void Line::Draw(GUI* pUI) const
{
	//Call Output::DrawLine to draw a line on the screen	
	pUI->DrawLn(Corner1, Corner2, ShpGfxInfo);

}

Line::Line(const Line* copy) :shape(copy->ShpGfxInfo)
{
	this->Corner1 = copy->Corner1;
	this->Corner2 = copy->Corner2;
	this->ID = copy->ID;


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

shape* Line::clone()
{
	shape* newShape = new Line(*this);

	return newShape;
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