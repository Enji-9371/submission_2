#include "shape.h"
#include "../GUI/GUI.h"

shape::shape()
{
	//srand(time(NULL));
	ID = rand() % 1000;   //certain random number for each square 
}

shape::shape(GfxInfo shapeGfxInfo)
{ 
	ShpGfxInfo = shapeGfxInfo;	//Default status is non-filled.
}
 
void shape::SetSelected(bool s)
{	ShpGfxInfo.isSelected = s; }

bool shape::IsSelected() const
{	return ShpGfxInfo.isSelected; }

void shape::ChngDrawClr(color Dclr)
{	ShpGfxInfo.DrawClr = Dclr; }

bool shape::IsDuplicated() const {
	return ShpGfxInfo.isDuplicated; }

void shape::ChngFillClr(color Fclr)
{
	ShpGfxInfo.isFilled = true;
	ShpGfxInfo.FillClr = Fclr;
}
void shape::ChngDrawWidth(int Wnum)
{
	ShpGfxInfo.BorderWdth = Wnum;
}

void shape::setID(int id)
{
	ID = (id > 0) ? id : 0;
}

int shape::getID() const
{
	return ID;
}
