#pragma once
#include "Shape.h"
#include "../GUI/GUI.h"
#include <fstream>
#include <vector>
using namespace std;

//forward decl
class GUI;	

//A class that is responsible on everything related to shapes
class Graph
{
private:
	vector <shape*> shapesList; //a container to hold all shapes							   
	shape* selectedShape;	//pointer to the currently selected shape
	shape* copiedShape;
	vector <shape*> clipboard;
	int size = 0;
public:										
	Graph();
	~Graph();
	void Addshape(shape* pFig); //Adds a new shape to the shapesList
	void Draw(GUI* pUI) const;			//Draw the graph (draw all shapes)
	shape* Getshape(int x, int y); //Search for a shape given a point inside the shape
	shape* GetSelected(); //get the selected shape

	shape* GetSelectedShape() const;
	void UnselectShapes();
	void Sendtoback(GUI* pUI);

	void setCopied(shape*);
	shape* getCopied();
	void clearClipboard();
	void Hide(GUI* pUI);
	void UnHide(GUI* pUI);


	void copy();
	void paste(Point p);
    void Save(ofstream& outfile);	//Save all shapes to a file
	void Load(ifstream& inputfile); //Load all shapes from a file
	void stickimage(GUI* pGUI) const;
	void ZOOM_IN_OUT(double scale, double X, double Y);  //zooming function
	void RESIZE(double n);              //RESIZE FUNCTION
	void ROTATE();  //rotate a single shape by 90 deg
	void Duplicated(GUI* pGUI);
	void DeleteShapeFromList();
	bool MATCH(shape* shape1, shape* shape2);

};
