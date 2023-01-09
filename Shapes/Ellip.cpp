#include "Ellip.h"
#include<fstream>
Ellip::Ellip()
{

}

Ellip::Ellip(Point P1, Point P2, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	Center.x = (Corner1.x + Corner2.x) / 2;
	Center.y = (Corner1.y + Corner2.y) / 2;
}

Ellip::~Ellip()
{}


int* Ellip::Getshapeinfo()
{
	int arr[6];
	if (Corner1.y < Corner2.y) {
		arr[0] = Corner1.x;
		arr[1] = Corner1.y;
		arr[2] = Corner2.x - 1;
		arr[3] = Corner2.y - 1;
	}
	else
	{
		arr[0] = Corner2.x - 1;
		arr[1] = Corner2.y - 1;
		arr[2] = Corner1.x;
		arr[3] = Corner1.y;
	}
	arr[4] = sqrt(pow((Corner2.x - Corner1.x), 2) + (pow((Corner2.y - Corner1.y), 2)));
	arr[5] = sqrt(pow((Corner2.x - Corner1.x), 2) + (pow((Corner2.y - Corner1.y), 2)));
	return arr;
}


Ellip::Ellip(const Ellip* copy) :shape(copy->ShpGfxInfo)
{
	this->Corner1 = copy->Corner1;
	this->Corner2 = copy->Corner2;
	this->Center.x = copy->Center.x;
	this->Center.y = copy->Center.y;
	this->ID = copy->ID;
}


shape* Ellip::clone()
{
	shape* newShape = new Ellip(*this);

	return newShape;
}


void Ellip::Save(ofstream& outFile)
{
	string DrawColor;
	outFile << ID << Corner1.x << Corner1.y << Corner2.x << Corner2.y << DrawColor;
	GfxInfo info;
	outFile << info.BorderWdth;
	outFile << info.isFilled;
	outFile << info.isSelected;
	outFile << info.FillClr.ucBlue;
	outFile << info.FillClr.ucGreen;
	outFile << info.FillClr.ucRed;
	outFile << info.DrawClr.ucBlue;
	outFile << info.DrawClr.ucGreen;
	outFile << info.DrawClr.ucRed;
}
void Ellip::Move(Point P)
{

}


void Ellip::Load(ifstream& Infile)
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

void Ellip::Draw(GUI* pUI) const
{
	//Call Output::DrawEllip to draw an ellipse on the screen	
	pUI->DrawEllip(Corner1, Corner2, ShpGfxInfo);
}

bool Ellip::point_included(int x, int y)
{
	return true;
}

shape* Ellip::duplicate(GUI* pGUI) {
	Point p1, p2;
	p1.x = Corner1.x + 250;
	p1.y = Corner1.y;
	p2.x = Corner2.x + 250;
	p2.y = Corner2.y;
	GfxInfo info = ShpGfxInfo;
	ShpGfxInfo.isDuplicated = true;
	Ellip* L = new Ellip(p1, p2, info);
	return L;
}

void  Ellip::OPZOOM(double px, double py, double scale)  //function to zoom in or out according to the value of the scale factor
{
	Corner1.x = (Corner1.x * scale) - (scale * px) + px;
	Corner1.y = (Corner1.y * scale) - (scale * py) + py;
	Corner2.x = (Corner2.x * scale) - (scale * px) + px;
	Corner2.y = (Corner2.y * scale) - (scale * py) + py;
}
void Ellip::ResizeShape(double scale)  	//Resize a single ellipse
{
	Corner1.x = (Corner1.x * scale) - (Center.x * scale) + Center.x;
	Corner2.x = (Corner2.x * scale) - (Center.x * scale) + Center.x;
	Corner1.y = (Corner1.y * scale) - (Center.y * scale) + Center.y;
	Corner2.y = (Corner2.y * scale) - (Center.y * scale) + Center.y;
}

void Ellip::RotateShape()  	//Rotate a single ellipse
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