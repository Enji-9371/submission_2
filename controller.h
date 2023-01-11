#pragma once

#include "DEFS.h"
#include "Shapes/Graph.h"
#include "GUI/GUI.h"
#include <stack>
class operation; //forward declaration

//Main class that manages everything in the application.
class controller
{

    enum { MaxshapesCount = 200 };	//Maximum number of shapes

private:	

	Graph* pGraph;	//pointe to the grapg
	GUI* pGUI;		//Pointer to UI class
	int Shpcount = 0;		//Actual number of shapes
	shape* shapesList[MaxshapesCount];	//List of all shapes (Array of pointers)
	shape* Clipboard;
	int ID;
	stack<operation*> DoneStack; // Creating a stack called "Operations" to store the made operations
	stack<operation*> UndoneStack;  // Creating another stack called UnDoneStack to store 


public:	
	int multiSelect;//enabling multiSelect
	controller(); 
	~controller();
	
	// -- operation-Related Functions
	//Reads the input command from the user and returns the corresponding operation type
	operationType GetUseroperation() const;
	operation* createOperation(operationType) ; //Creates an operation
	void Run();
	Graph* getGraph() const;
	void AddShape(shape* pShp);
	int getShpCount() const;			
	void setID(int Scount);

	// -- Interface Management Functions
	GUI *GetUI() const; //Return pointer to the UI
	void UpdateInterface() const;	//Redraws all the drawing window	
	void UnSelectFigures(int mul) const;
	void Undo();
	void Redo();
	void newOp(operation* newOp);

	operation* PreviousDone();  // Returns a pointer to the last added operation to the stack
	operation* PreviousUndone();		// Return a pointer to the last undone operation in the stack

};


