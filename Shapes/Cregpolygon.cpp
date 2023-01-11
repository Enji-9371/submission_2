#include "Cregpolygon.h"
#include <math.h>
#include <corecrt_math_defines.h>
#include <fstream>


polygon::polygon(Point p1, Point p2, int i, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	center.x = p1.x;
	center.y = p1.y;
	point1.x = p2.x;
	point1.y = p2.y;
	num = i;
	distance = sqrt(pow(point1.x - center.x, 2) + pow((point1.y - center.y), 2));
}
polygon::~polygon()
{}

void polygon::hideShape(GUI* pUI)
{
	//pUI->StickImage("images\\MenuIcons\\image.jpg", center.x, center.y, 200, 200);
}

polygon::polygon()
{
}

int* polygon::Getshapeinfo()
{
	int arr[4];
	arr[0] = x[0];// get x
	arr[1] = y[1];//get y
	arr[2] = sqrt(pow((x[1] - x[0]), 2) + (pow((y[1] - y[0]), 2)));//get width
	arr[3] = sqrt(pow((x[1] - x[0]), 2) + (pow((y[1] - y[0]), 2)));// get height
	return arr;
}

polygon::polygon(const polygon* copy) :shape(copy->ShpGfxInfo)
{
	this->center = copy->center;
	this->point1= copy->point1;
	this->num = copy->num;
	this->distance = copy->distance;
	this->ID = copy->ID;

}

shape* polygon::clone()
{
	shape* newShape = new polygon(*this);

	return newShape;
}

void polygon::Draw(GUI* pUI) const
{
	if (num == 4) {
		for (int i = 0; i < num; i++)
		{

			int vertixofX = center.x + distance * cos(i * 2 * M_PI / num);
			int vertixofY = center.y + distance * sin(i * 2 * M_PI / num);
			arrayX[i] = vertixofX; arrayY[i] = vertixofY;
		}
		pUI->DrawPolygon(arrayX, arrayY, num, ShpGfxInfo);
	}
	else
	{
		double x = ((num - 2) * M_PI) / (2 * num);
		for (int i = 0; i < num; i++)
		{

			int vertixofX = center.x + distance * cos(i * 2 * M_PI / num + x);
			int vertixofY = center.y + distance * sin(i * 2 * M_PI / num + x);
			arrayX[i] = vertixofX;
			arrayY[i] = vertixofY;
		}pUI->DrawPolygon(arrayX, arrayY, num, ShpGfxInfo);
	}

	double x = ((num - 2) * M_PI) / (2 * num);
	for (int i = 0; i < num; i++)
	{
		int vertixofX = center.x + distance * cos(i * 2 * M_PI / num + x);
		int vertixofY = center.y + distance * sin(i * 2 * M_PI / num + x);
		arrayX[i] = vertixofX;
		arrayY[i] = vertixofY;
	}
	pUI->DrawPolygon(arrayX, arrayY, num, ShpGfxInfo);



}

shape* polygon::duplicate(GUI* pGUI) {
	Point p1, p2;
	p1.x = center.x + 25;
	p1.y = center.y;
	p2.x = point1.x + 25;
	p2.y = point1.y;
	GfxInfo info = ShpGfxInfo;
	ShpGfxInfo.isDuplicated = true;
	polygon* p = new polygon(p1, p2, num, ShpGfxInfo);
	return p;
}

void polygon::Move(Point P)
{

}
void polygon::Save(ofstream& outFile)
{
	string DrawColor;
	outFile << ID << DrawColor;
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

void polygon::Load(ifstream& inFile)
{
	type = "RegPoly";
	int x;
	string jump;

	inFile >> x;
	num = x;
	inFile >> x;
	center.x = x;

	inFile >> x;
	center.y = x;

	inFile >> x;

	point1.x = x;

	inFile >> x;
	point1.y = x;

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

bool polygon::point_included(int x, int y) 
{
	double area = 0;
	int j = num - 1;

	double polyarea = 0.0;
	for (int i = 0; i < num; i++)
	{
		polyarea += (arrayX[j] + arrayX[i]) * (arrayY[j] - arrayY[i]);
		j = i;
	}
	polyarea = abs(polyarea / 2.0);

	for (int i = 0; i < num; i++)
	{
		area = area + abs(0.5 * ((x * arrayY[i]) - (arrayX[i] * y) + (arrayX[i] * arrayY[j]) - (arrayX[j] * arrayY[i]) + (arrayX[j] * y) - (x * arrayY[j])));
		j = i;
	};

	if (polyarea == area)
		return true;
	else return false;
}


void  polygon::OPZOOM(double px, double py, double scale)  //function to zoom in or out according to the value of the scale factor
{
	for (int i = 0; i < num; i++)
	{
		double yy = arrayY[i];
		double xx = arrayX[i];
		double vertix_py = py + (scale * yy) - (scale * py);
		arrayY[i] = vertix_py;
		double vertix_px = px + (scale * xx) - (scale * px);
		arrayX[i] = vertix_px;
	}
}

void polygon::ResizeShape(double scale)  	//Resize a single regular polygon
{
	for (int i = 0; i < num; i++)
	{
		arrayX[i] = center.x + (arrayX[i] * scale) - (center.x * scale);
		arrayY[i] = center.x + (arrayY[i] * scale) - (center.y * scale);
	}

}

void polygon::RotateShape()  	//Rotate a single regular polygon
{
	for (int i = 0; i < num; i++)
	{
		double YY = arrayY[i];
		double XX = arrayX[i];
		double VERTIX_Y = XX + center.y - center.x;
		double VERTIX_X = center.y + center.x - YY;
		arrayY[i] = VERTIX_Y;
		arrayX[i] = VERTIX_X;
	}
}
void polygon::Scramble(int i, int j)
{
	int temp1 = (rand() % 1000);
	int temp2 = (rand() % 500);
	center.x = i;
	center.y = j;
	point1.x = i + 150;
	point1.y = j;

}