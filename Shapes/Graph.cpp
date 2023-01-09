#include "Graph.h"
#include "../GUI/GUI.h"
#include"../Shapes/Shape.h"
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

void Graph::Save(ofstream& outfile) {
	int sv = shapesList.size();
	outfile << " Shape_ Type  shape_ID  Shape_parameters " << endl; 
	for (int i = 0; i < sv; i++) {
		shapesList[i]->Save(outfile);
	}

}




void Graph::DeleteShapeFromList()
{
	int size, count;
	size = shapesList.size();
	count = 0;
	for (auto& shapePointer : shapesList)
	{

		if (shapePointer->IsSelected())
		{
			//delete &shapePointer;
			shapesList.erase(shapesList.begin() + count);
			count--;
		}
		count++;
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