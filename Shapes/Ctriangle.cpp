#include "Ctriangle.h"


Ctriangle::Ctriangle(Point P1, Point P2, Point P3, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	Corner3 = P3;
	Center.x = (Corner1.x + Corner2.x + Corner3.x) / 3;
	Center.y = (Corner1.y + Corner2.y + Corner3.y) / 3;
}
Ctriangle::~Ctriangle() {}
void Ctriangle::Save(ofstream& OutFile)
{
	OutFile << "TRIANGLE" << " " << Corner1.x << " " << Corner1.y << " " << Corner2.x << " " << Corner2.y << " " << Corner3.x << " " << Corner3.y << " " << (ShpGfxInfo.isFilled) << " " << to_string(ShpGfxInfo.FillClr.ucRed) << " " << to_string(ShpGfxInfo.FillClr.ucGreen) << " " << to_string(ShpGfxInfo.FillClr.ucBlue) << " " << to_string(ShpGfxInfo.DrawClr.ucRed) << " " << to_string(ShpGfxInfo.DrawClr.ucGreen) << " " << to_string(ShpGfxInfo.DrawClr.ucBlue) << " " << (ShpGfxInfo.BorderWdth) << endl;

}
void Ctriangle::hideShape(GUI* pUI)
{
	//pUI->StickImage("images\\MenuIcons\\image.jpg", Corner1.x, Corner1.y, 200, 200);
}

Ctriangle::Ctriangle()
{}
int* Ctriangle::Getshapeinfo()
{
	int arr[12];
	int y1 = Corner2.y - sqrt(pow((Corner2.x - Corner1.x), 2) + (pow((Corner2.y - Corner1.y), 2)));
	arr[0] = Corner2.x - 4;
	arr[1] = y1;
	arr[5] = sqrt(pow((Corner2.x - Corner1.x), 2) + (pow((Corner2.y - Corner1.y), 2))) + 5;
	arr[4] = sqrt(pow((Corner2.x - Corner3.x), 2) + (pow((Corner2.y - Corner3.y), 2))) + 5;
	arr[6] = Corner1.x;
	arr[7] = Corner1.y;
	arr[8] = Corner2.x;
	arr[9] = Corner2.y;
	arr[10] = Corner3.x;
	arr[11] = Corner3.y;
	return arr;
}


void Ctriangle::Load(ifstream& inFile)
{
	type = "Triangle";
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
	Corner3.x = x;

	inFile >> x;
	Corner3.y = x;
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


void Ctriangle::Move(Point P)
{
	double CenterX = (Corner1.x + Corner2.x + Corner3.x) / 3;
	double CenterY = (Corner1.y + Corner2.y + Corner3.y) / 3;
	double dx = P.x - CenterX;
	double dy = P.y - CenterY;
	int Temp1x = Corner1.x;
	int Temp1y = Corner1.y;
	int Temp2x = Corner2.x;
	int Temp2y = Corner2.y;
	int Temp3x = Corner3.x;
	int Temp3y = Corner3.y;
	Corner1.x = Temp1x + dx;
	Corner1.y = Temp1y + dy;
	Corner2.x = Temp2x + dx;
	Corner2.y = Temp2y + dy;
	Corner3.x = Temp3x + dx;
	Corner3.y = Temp3y + dy;
}
void Ctriangle::Draw(GUI* pUI) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pUI->DrawTriangle(Corner1, Corner2, Corner3, ShpGfxInfo);
}

Ctriangle::Ctriangle(const Ctriangle* copy) :shape(copy->ShpGfxInfo)
{
	this->Corner1 = copy->Corner1;
	this->Corner2 = copy->Corner2;
	this->Corner3 = copy->Corner3;
	this->ID = copy->ID;

}

shape* Ctriangle::clone()
{
	shape* newShape = new Ctriangle(*this);

	return newShape;
}



double Ctriangle::triarea(int x1, int x2, int x3, int y1, int y2, int y3) {
	double triangle_area = abs(x1 * (y2 - y3) - y1 * (x2 - x3) + ((x2 * y3) - (y2 * x3))) / 2;
	return triangle_area;
}

shape* Ctriangle::duplicate(GUI* pGUI) {
	Point p1, p2, p3;
	p1.x = Corner1.x + 250;
	p1.y = Corner1.y;
	p2.x = Corner2.x + 250;
	p2.y = Corner2.y;
	p3.x = Corner3.x + 250;
	p3.y = Corner3.y;
	GfxInfo info = ShpGfxInfo;
	ShpGfxInfo.isDuplicated = true;
	Ctriangle* L = new Ctriangle(p1, p2, p3, info);
	return L;
}



bool Ctriangle::point_included(int x, int y) {
	double areaoftriangle = triarea(Corner1.x, Corner2.x, Corner3.x, Corner1.y, Corner2.y, Corner3.y);
	double area1, area2, area3;
	area1 = triarea(x, Corner2.x, Corner3.x, y, Corner1.y, Corner3.y);
	area2 = triarea(Corner1.x, x, Corner3.x, Corner1.y, y, Corner3.y);
	area3 = triarea(Corner1.x, Corner2.x, x, Corner1.y, Corner2.y, y);

	if (areaoftriangle == area1 + area2 + area3)
		return true;

	else
		return false;
}

void Ctriangle::OPZOOM(double px, double py, double scale)  //function to zoom in or out according to the value of the scale factor
{

	Corner1.x = (Corner1.x * scale) - (scale * px) + px;
	Corner1.y = (Corner1.y * scale) - (scale * py) + py;
	Corner2.x = (Corner2.x * scale) - (scale * px) + px;
	Corner2.y = (Corner2.y * scale) - (scale * py) + py;
	Corner3.x = (Corner3.x * scale) - (scale * px) + px;
	Corner3.y = (Corner3.y * scale) - (scale * py) + py;

}
void Ctriangle::ResizeShape(double scale)  	//Resize a single triangle
{
	Corner1.x = Corner1.x * scale - (Center.x * scale) + Center.x;
	Corner1.y = Corner1.y * scale - (Center.y * scale) + Center.y;
	Corner2.x = Corner2.x * scale - (Center.x * scale) + Center.x;
	Corner2.y = Corner2.y * scale - (Center.y * scale) + Center.y;
	Corner3.x = Corner3.x * scale - (Center.x * scale) + Center.x;
	Corner3.y = Corner3.y * scale - (Center.y * scale) + Center.y;
}
void Ctriangle::RotateShape()  	//Rotate a single triangle
{
	int C1x = Corner1.x;
	int C2x = Corner2.x;
	int C3x = Corner3.x;
	int C1y = Corner1.y;
	int C2y = Corner2.y;
	int C3y = Corner3.y;
	Corner1.x = Center.y + Center.x - C1y;
	Corner2.x = Center.y + Center.x - C2y;
	Corner3.x = Center.y + Center.x - C3y;
	Corner1.y = C1x + Center.y - Center.x;
	Corner2.y = C2x + Center.y - Center.x;
	Corner3.y = C3x + Center.y - Center.x;
}