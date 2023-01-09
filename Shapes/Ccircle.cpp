#include "Ccircle.h"

#include <fstream>

Ccircle::Ccircle(Point P1, Point P2, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	center = P1;
	border = P2;
	rad= sqrt(((center.x - border.x) * (center.x - border.x)) + ((center.y - border.y) * (center.y - border.y)));
}

Ccircle::~Ccircle()
{}


void Ccircle::Save(ofstream& OutFile)
{
	OutFile << "circle" << " " << center.x << " " << center.y << " " << border.x << " " << border.y << " " << ShpGfxInfo.isFilled;
	OutFile << " " << to_string(ShpGfxInfo.FillClr.ucRed) << " " << to_string(ShpGfxInfo.FillClr.ucGreen) << " " << to_string(ShpGfxInfo.FillClr.ucBlue) << " " << to_string(ShpGfxInfo.DrawClr.ucRed) << " " << to_string(ShpGfxInfo.DrawClr.ucGreen) << " " << to_string(ShpGfxInfo.DrawClr.ucBlue) << " " << (ShpGfxInfo.BorderWdth) << endl;

}

void Ccircle::Load(ifstream& Infile)
{
}


void Ccircle::Draw(GUI* pUI) const
{
	double rad = sqrt((center.x - border.x) * (center.x - border.x) + (center.y - border.y) * (center.y - border.y));
	//Call Output::Drawcircle to draw a Circle on the screen	
	pUI->DrawCircle(center,rad , ShpGfxInfo);
}

bool Ccircle::point_included(int x, int y) {

	double radius = sqrt(pow(center.x - border.x, 2) + pow(center.y - border.y, 2));
	double d = sqrt(pow(x - center.x, 2) + pow(y - center.y, 2));	 //distance formula for the circle
	if (d <= radius)
		return true;
	else
		return false;
}

void Ccircle::Move(Point P)
{
	double rad = sqrt((center.x - border.x) * (center.x - border.x) + (center.y - border.y) * (center.y - border.y));

	center.x = P.x;
	center.y = P.y;
	border.x = center.x + rad;
	border.y = center.y;
}




shape* Ccircle::copy()  
{
	shape* cir = new Ccircle(center, border, ShpGfxInfo);
	return cir;
}

shape* Ccircle::Paste(Point) //just to run
{
	shape* ptr=nullptr;
	return ptr;
}

void  Ccircle::OPZOOM(double px, double py, double scale)  //function to zoom in or out according to the value of the scale factor
{
	rad = rad * scale;
	Corner1.x = (Corner1.x * scale) - (scale * px) + px;
	Corner1.y = (Corner1.y * scale) - (scale * py) + py;
	Corner2.x = (Corner2.x * scale) - (scale * px) + px;
	Corner2.y = (Corner2.y * scale) - (scale * py) + py;
}

shape* Ccircle::duplicate(GUI* pGUI) {
	int rad = sqrt(((center.x - border.x) * (center.x - border.x)) + ((center.y - border.y) * (center.y - border.y)));
	Point corner3;
	corner3.x = center.x + 2 * rad;
	corner3.y = center.y;
	Point corner4;
	corner4.x = border.x + 2 * rad;
	corner4.y = border.y;
	GfxInfo info = ShpGfxInfo;
	ShpGfxInfo.isDuplicated = true;
	Ccircle* c = new Ccircle(corner3, corner4, info);
	return c;
}

void Ccircle::ResizeShape(double scale)  	//Resize a single regular polygon
{
	rad = rad * scale;
}

void Ccircle::RotateShape()  	//Rotate a single regular polygon
{}
