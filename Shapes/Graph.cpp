#include "Graph.h"
#include "../GUI/GUI.h"
#include"../Shapes/Shape.h"
#include "../controller.h"
#include "Line.h"
#include "Squr.h"
#include "Rect.h"
#include "Ellip.h"
#include "Cregpolygon.h"
#include "Ctriangle.h"
#include "Ccircle.h"
#include <iostream>
using namespace std;
Graph::Graph()
{
	selectedShape = nullptr;
}

Graph::~Graph()
{
	selectedShape = nullptr;
}

//==================================================================================//
//						shapes Management Functions								//
//==================================================================================//

//Add a shape to the list of shapes
void Graph::Addshape(shape* pShp)
{
	//Add a new shape to the shapes vector
	shapesList.push_back(pShp);	
}

void Graph::setCopied(shape* copied) {
	copiedShape = copied;
}

shape* Graph::getCopied() {
	return copiedShape;
}

void Graph::clearClipboard()
{
	clipboard.clear();

}

void Graph::copy()
{
	for (int i = 0; i < shapesList.size(); i++) {
		if (shapesList[i]->IsSelected()) {
			clipboard.push_back(shapesList[i]);
		}
	}

	UnselectShapes();
}

void Graph::paste(Point p)

{
	if (!clipboard.empty()) {

		for (int i = 0; i < clipboard.size(); i++) {

			shape* newShape = clipboard[i]->clone();
			newShape->Move(p);
			shapesList.push_back(newShape);

		}
		clearClipboard();
	}
	UnselectShapes();


}

void Graph::CCUT()
{
	for (int i = 0; i < shapesList.size(); i++) {
		if (shapesList[i]->IsSelected()) {
			clipboard.push_back(shapesList[i]);
			shapesList.erase(shapesList.begin() + i);

		}
	}
	}
void Graph::Hide(GUI* pUI) {

	for (auto shapePointer : shapesList) {
		shapePointer->IsHidden(true);
	}
	Draw(pUI);
}

void Graph::UnHide(GUI* pUI) {

	for (auto shapePointer : shapesList) {
		shapePointer->IsHidden(false);
	}
	Draw(pUI);
}


void Graph::Sendtoback(GUI* pUI)
{
	if (GetSelected() == nullptr) {
		pUI->PrintMessage("Select a shape first ");
	}
	else if (GetSelected() != nullptr)
	{
		pUI->PrintMessage("Select the shape to send back : ");
		shape* temp = shapesList[0];
		shapesList[0] = GetSelected();
		for (int i = 0; i < shapesList.size(); i++) {
			if (shapesList[i] == GetSelected()) {
				shapesList[0] = GetSelected();
				shapesList[i] = temp;
			}

		}
		for (auto shapePointer : shapesList) {
			shapePointer->Draw(pUI);
		}

		pUI->ClearStatusBar();
	}

	else if (GetSelected() == nullptr)
	{
		pUI->PrintMessage("Please select a shape first");
		color col = pUI->getCrntFillColor();


	}
}


shape* Graph::GetSelected()
{
	return selectedShape;
}
////////////////////////////////////////////////////////////////////////////////////
//Draw all shapes on the user interface
void Graph::Draw(GUI* pUI) const
{
	pUI->ClearDrawArea();
	for (auto shapePointer : shapesList) {
		shapePointer->Draw(pUI);
		if (shapePointer->IsSticked)
		{
			this->stickimage(pUI);
		}
	}
}

void Graph::Save(ofstream& outfile)
{
	outfile << shapesList.size() << endl;
	for (auto& shapePointer : shapesList)
	{
		shapePointer->Save(outfile);
		shapePointer->setSaved();

	}

	outfile.close();
}

void Graph::load(ifstream& inputfile, GUI* pUI, Graph* pGr)
{
	string x;
	string type;
	int noOfShapes;

	inputfile >> noOfShapes;
	int y = 0;
	shape* p;

	for (int i = 0; i < noOfShapes; i++)
	{
		y++;

		string z;
		inputfile >> type;
		if (type == "Line")
		{
			p = new Line();
			p->Load(inputfile);
			Addshape(p);
		}
		else if (type == "Circle")
		{
			p = new Ccircle();

			p->Load(inputfile);

			Addshape(p);
		}
		else if (type == "Triangle")
		{
			p = new Ctriangle();
			p->Load(inputfile);
			Addshape(p);
		}
		else if (type == "Rect")
		{

			p = new Rect();
			p->Load(inputfile);
			Addshape(p);
		}
		else if (type == "RegPoly")
		{
			p = new polygon();
			p->Load(inputfile);
			Addshape(p);

		}
		else if (type == "Square")
		{
			p = new Squr();
			p->Load(inputfile);
			Addshape(p);
		}
		else if (type == "Ellipse")
		{
			p = new Ellip();
			p->Load(inputfile);
			Addshape(p);
		}




	}

	inputfile.close();
}





void Graph::DELSHAPE()
{
	int size, num;
	size = shapesList.size();
	num = 0;
	for (auto& shapePointer : shapesList)
	{

		if (shapePointer->IsSelected())
		{
			;
			shapesList.erase(shapesList.begin() + num);
			num--;
		}
		num++;
	}
}




shape* Graph::Getshape(int x, int y)
{
	for (auto shapePointer = shapesList.rbegin(); shapePointer != shapesList.rend(); ++shapePointer)
		if ((*shapePointer)->point_included(x, y))
		{
			selectedShape = (*shapePointer);
			return selectedShape;
			break;
		}
		else
		{
			return nullptr;
		}
	return nullptr;
}
void Graph::UnselectShapes()
{
	for (auto shapePointer : shapesList)
		shapePointer->SetSelected(false);
	selectedShape = nullptr;
}

shape* Graph::GetSelectedShape() const {
	return selectedShape;
}
void Graph::ZOOM_IN_OUT(double scale, double X, double Y)  //zooming function to determine the point(origin) and the scale factor
{
	for (int k = 0; k < shapesList.size(); k++)  //looping on the list of shapes
	{

		shapesList[k]->OPZOOM(X, Y, scale); //zooming shapes

	}
}

void Graph::RESIZE(double scale)  //loop on the shape list then resize the selected shape
{
	for (int i = 0; i < shapesList.size(); i++) 
	{
		if (selectedShape == shapesList[i]) 
		{
			shapesList[i]->ResizeShape(scale);
		}
	}
}

void Graph::ROTATE() //loop on the shape list then rotate the selected shape
{
	for (int k = 0; k < shapesList.size(); k++)
	{
		if (selectedShape == shapesList[k]) {
			shapesList[k]->RotateShape();
		}
	}
}

void Graph::stickimage(GUI* pUI) const
{
	for (int i = 0; i < shapesList.size(); i++)
	{
		if (shapesList[i]->IsSelected())
		{
			int x = shapesList[i]->Getshapeinfo()[0];
			int y = shapesList[i]->Getshapeinfo()[1];
			int width = shapesList[i]->Getshapeinfo()[2];
			int height = shapesList[i]->Getshapeinfo()[3];
			pUI->StickImage("images\\MenuIcons\\image.jpg", x, y, width, height);
		}
	}
}


void Graph::Duplicated(GUI* pGUI)
{
	size = shapesList.size();

	for (int i = 0; i < size; i++) {

		shapesList.push_back(shapesList[i]->duplicate(pGUI));
	}
}

bool Graph::MATCH(shape*  shape1, shape*  shape2)   //match function
{
	for (int i = 0; i < shapesList.size(); i++)
	{
		if (shapesList[i]->getID() == shape1->getID())
		{
			for (int j = 0; j < shapesList.size(); j++)
			{
				if (shapesList[j]->getID() == shape2->getID())
				{
					//pUI->PrintMessage("matched");
					return true;
					/*DeleteShapeFromList(shape1);
					DeleteShapeFromList(shape2);*/
					shapesList[i]->SetSelected(false);
					shapesList[j]->SetSelected(false);
					delete shapesList[i];
					delete shapesList[j];
					shapesList.erase(shapesList.begin() + i);
					shapesList.erase(shapesList.begin() + j);
				}
				else
				{
					//GUI* pUI = pControl->GetUI();
					//pUI->PrintMessage("not matched");
					return false;
					shapesList[i]->IsHidden(true);
					shapesList[j]->IsHidden(true);
				}
			}
		}
	}
}

void  Graph::HIDEALL()  //hide all shapes
{
	for (int i = 0; i < shapesList.size(); i++)
	{
		shapesList[i]->IsHidden(true);
	}
}


bool Graph::check_if_finished()  //check if the game is finished
{
	if (shapesList.size() == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}