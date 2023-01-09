#include "Irregpoly.h"

irr_polygon::irr_polygon()
{

}

irr_polygon::irr_polygon(Point* p1, int x, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	array_points = p1;
	num = x;
	int all_x = 0;
	int all_y= 0;
	/*for (int i = 0; i < num; i++)
	{
		Array_X[i] = array_points[i].x;
		Array_Y[i] = array_points[i].y;
		all_x = all_x + Array_X[i];
		Center.x = Array_X[i] / num;
		all_y = all_y + Array_Y[i];
		Center.y = Array_Y[i] / num;
	}*/

}
void irr_polygon::Move(Point P)
{

}

irr_polygon::~irr_polygon()
{

}

void irr_polygon::Save(ofstream& outFile)
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

void irr_polygon::Load(ifstream& Infile)
{
string DrawColor;
    Infile >> ID >> DrawColor;
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

void irr_polygon::Draw(GUI* pUI) const
{

	for (int i = 0; i < num; i++)
	{
		Array_X[i] = array_points[i].x;
		Array_Y[i] = array_points[i].y;
	}

	//Call Output::Draw irrpolygon to draw an irrpolygon on the screen	
	pUI->DrawPolygon(Array_X, Array_Y, num, ShpGfxInfo);

};

shape* irr_polygon::copy()  
{
	shape* ptr = new irr_polygon(array_points, num, ShpGfxInfo);
	return ptr;
}

shape* irr_polygon::duplicate(GUI* pGUI) {
	return nullptr;
}



shape* irr_polygon::Paste(Point) //just to run
{
	shape* ptr = nullptr;
	return ptr;
}
bool irr_polygon::point_included(int x, int y) 
{
	double area = 0;
	int j = num - 1;

	double polyarea = 0.0;
	for (int i = 0; i < num; i++)
	{
		polyarea += (Array_X[j] + Array_X[i]) * (Array_Y[j] - Array_Y[i]);
		j = i;
	}
	polyarea = abs(polyarea / 2.0);

	for (int i = 0; i < num; i++)
	{
		area = area + abs(0.5 * ((x * Array_Y[i]) - (Array_X[i] * y) + (Array_X[i] * Array_Y[j]) - (Array_X[j] * Array_Y[i]) + (Array_X[j] * y) - (x * Array_Y[j])));
		j = i;
	};

	if (polyarea == area)
		return true;
	else return false;
}

void  irr_polygon::OPZOOM(double px, double py, double scale)  //function to zoom in or out according to the value of the scale factor
{
	for (int i = 0; i < num; i++)
	{
		double yy = Array_Y[i];
		double xx = Array_X[i];
		double vertix_py = py + (yy * scale) - (scale * py);
		Array_Y[i] = vertix_py;
		double vertix_px =px + (xx * scale) - (scale * px);
		Array_X[i] = vertix_px;
	}
}

void irr_polygon::ResizeShape(double scale)  	//Resize a single irregular polygon
{
	for (int i = 0; i < num; i++)
	{
		Array_X[i] = (Array_X[i] * scale) - (scale * Center.x) + Center.x;
		Array_Y[i] = (Array_Y[i] * scale) - (scale * Center.y) + Center.y;
	}
}

void irr_polygon::RotateShape()  	//Rotate a single irregular polygon
{
	for (int i = 0; i < num; i++)
	{
		double YY = Array_Y[i];
		double XX = Array_X[i];
		double VERTIX_Y = XX + Center.y - Center.x;
		double VERTIX_X = Center.y + Center.x - YY;
		Array_Y[i] = VERTIX_Y;
		Array_X[i] = VERTIX_X;
	}
}

