#include "Ccircle.h"

#include <fstream>

Ccircle::Ccircle(Point P1, Point P2, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	center = P1;
	border = P2;
	rad= sqrt(((center.x - border.x) * (center.x - border.x)) + ((center.y - border.y) * (center.y - border.y)));

}

Ccircle::Ccircle()
{}

Ccircle::~Ccircle()
{}

void Ccircle::hideShape(GUI* pUI)
{
	//pUI->StickImage("images\\MenuIcons\\image.jpg", center.x, center.y, 200, 200);
}


void Ccircle::Save(ofstream& OutFile)
{
	OutFile << "circle" << " " << center.x << " " << center.y << " " << border.x << " " << border.y << " " << ShpGfxInfo.isFilled;
	OutFile << " " << to_string(ShpGfxInfo.FillClr.ucRed) << " " << to_string(ShpGfxInfo.FillClr.ucGreen) << " " << to_string(ShpGfxInfo.FillClr.ucBlue) << " " << to_string(ShpGfxInfo.DrawClr.ucRed) << " " << to_string(ShpGfxInfo.DrawClr.ucGreen) << " " << to_string(ShpGfxInfo.DrawClr.ucBlue) << " " << (ShpGfxInfo.BorderWdth) << endl;

}

int* Ccircle::Getshapeinfo()
{
	int arr[10];
	arr[0] = center.x - rad;
	arr[1] = center.y - rad;
	arr[2] = center.x + rad;
	arr[3] = center.y + rad;
	arr[4] = rad * 2;
	arr[5] = rad * 2;
	arr[6] = center.x;
	arr[7] = center.y;
	arr[8] = rad;
	return arr;
}


void Ccircle::Load(ifstream& inFile)
{
	type = "Circle";
	int x;
	string jump;

	inFile >> x;
	center.x = x;

	inFile >> x;
	center.y = x;

	inFile >> x;

	border.x = x;

	inFile >> x;
	border.y = x;

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




Ccircle::Ccircle(const Ccircle* copy) :shape(copy->ShpGfxInfo)
{
	this->center = copy->center;
	this->border = copy->border;
	this->rad = copy->rad;
	this->ID = copy->ID;

}

shape* Ccircle::clone()
{
	shape* newShape = new Ccircle(*this);

	return newShape;
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

void Ccircle::RotateShape()  	//Circle cannot be rotated
{}
