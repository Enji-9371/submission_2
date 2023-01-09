#include "Squr.h"
#include<fstream>
#include "../GUI/GUI.h"
#include "math.h"
Squr::Squr()
{
}
Squr::Squr(Point P1, Point P2, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	L = sqrt(pow((P2.x - P1.x), 2) + pow((P2.y - P1.y), 2));
	P2.x = P1.x + L / sqrt(2);
	P2.y = P1.y + L / sqrt(2);
	Corner1 = P1;
	Corner2 = P2;
	arrX[0] = Corner1.x;
	arrY[0] = Corner1.y;
	arrX[1] = Corner1.x + L;
	arrY[1] = Corner1.y;
	arrX[2] = Corner1.x + L;
	arrY[2] = Corner1.y + L;
	arrX[3] = Corner1.x;
	arrY[3] = Corner1.y + L;
}


int* Squr::Getshapeinfo()
{
	int listofparameters[4];
	listofparameters[0] = arrX[0] - 10;
	listofparameters[1] = arrY[0] - 10;
	listofparameters[2] = abs(arrX[0] - arrX[1]) + 15;
	listofparameters[3] = abs(arrY[0] - arrY[2]) + 15;
	return listofparameters;
}


void Squr::Move(Point P)
{
	double CenterX = (Corner1.x + Corner2.x) / 2;
	double CenterY = (Corner1.y + Corner2.y) / 2;
	double dx = P.x - CenterX;
	double dy = P.y - CenterY;
	int Temp1x = Corner1.x;
	int Temp1y = Corner1.y;
	int Temp2x = Corner2.x;
	int Temp2y = Corner2.y;

	Corner1.x = Temp1x + dx;
	Corner1.y = Temp1y + dy;
	Corner2.x = Temp2x + dx;
	Corner2.y = Temp2y + dy;

}

Squr::~Squr()
{}

void Squr::Save(ofstream& OutFile)
{
	OutFile << "square" << " " << 4 << " " << Corner1.x << " " << Corner1.y << " " << Corner2.x << " " << Corner2.y << " " << ShpGfxInfo.isFilled;
	OutFile << " " << to_string(ShpGfxInfo.FillClr.ucRed) << " " << to_string(ShpGfxInfo.FillClr.ucGreen) << " " << to_string(ShpGfxInfo.FillClr.ucBlue) << " " << to_string(ShpGfxInfo.DrawClr.ucRed) << " " << to_string(ShpGfxInfo.DrawClr.ucGreen) << " " << to_string(ShpGfxInfo.DrawClr.ucBlue) << " " << (ShpGfxInfo.BorderWdth) << endl;
}

shape* Squr::clone()
{
	shape* newShape = new Squr(*this);
	return newShape;
}


void Squr::Load(ifstream& Infile)
{
	string DrawColor;
	Infile >> ID >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y >> DrawColor;
	GfxInfo info;
	Infile >> info.BorderWdth;
	Infile >> info.isFilled;
	Infile >> info.isSelected;
	Infile >> info.FillClr.ucBlue;
	Infile >> info.FillClr.ucGreen;
	Infile >> info.FillClr.ucRed;
	Infile >> info.DrawClr.ucBlue;
	Infile >> info.DrawClr.ucGreen;
	Infile >> info.DrawClr.ucRed;
}

void Squr::Draw(GUI* pUI) const
{
	//Call Output::DrawSqur to draw a square on the screen	
	pUI->DrawSqur(Corner1, Corner2, ShpGfxInfo);
}

Squr::Squr(const Squr* copy) :shape(copy->ShpGfxInfo)
{
	this->Corner1 = copy->Corner1;
	this->Corner2 = copy->Corner2;
	this->ID = copy->ID;
}

bool Squr::point_included(int x, int y) {
	double length;
	length = sqrt(pow(Corner2.x - Corner1.x, 2) + pow(Corner2.y - Corner1.y, 2));
	if (x > Corner1.x && x<Corner1.x + length && y>Corner1.y && y < Corner1.y + length)
		return true;

	else
		return false;
}
void Squr::OPZOOM(double px, double py, double scale)  //function to zoom in or out according to the value of the scale factor
{
	Corner1.x = (Corner1.x * scale) - (scale * px) + px;
	Corner2.x = (Corner2.x * scale) - (scale * px) + px;
	Corner1.y = (Corner1.y * scale) - (scale * py) + py;
	Corner2.y = (Corner2.y * scale) - (scale * py) + py;
}

shape* Squr::duplicate(GUI* pGUI) {
	Point p1, p2;
	p1.x = Corner1.x + 250;
	p1.y = Corner1.y;
	p2.x = Corner2.x + 250;
	p2.y = Corner2.y;
	GfxInfo info = ShpGfxInfo;
	ShpGfxInfo.isDuplicated = true;
	Squr* L = new Squr(p1, p2, info);
	return L;
}

void Squr::ResizeShape(double scale)  	//Resize a single squre
{
	L =scale*L;
	Corner2.y = (Corner1.y + L / sqrt(2));
	Corner2.x = (Corner1.x + L / sqrt(2));
} 

void Squr::RotateShape()  	//square cannot be rotated
{}