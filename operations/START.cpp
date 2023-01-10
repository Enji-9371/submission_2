#include "START.h"
#include "..\controller.h"
#include<iostream>

opStart::opStart(controller* pCont) :operation(pCont)
{}
opStart::~opStart()
{}

//Execute the operation
void opStart::Execute()
{
	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();
	Graph* pGraph = pControl->getGraph();

	pUI->PrintMessage("SELECT A SHAPE: ");
	shape* pShape1 = pGraph->GetSelected();
	if (pShape1->IsSelected() == true)
	{
		pShape1->duplicate(pUI);
		//pGraph->Scramble();
		pGraph->Hide_shapes(pUI);
		pUI->PrintMessage("SELECT A CARD: ");
		shape* pShape2 = pGraph->GetSelected();
		if (pShape2->IsSelected() == true)
		{
			int counter = 0;
			bool l;
			l = pGraph->MATCH(pShape1, pShape2);
			if (l == true)
			{
				counter = counter + 3;
			}
			else
			{
				counter = counter + 1;
			}
			cout << "your score is:  " << counter << endl;
		}
		bool m;
		m=pGraph->check_if_finished();
		if (m == true)
		{
			pUI->PrintMessage("CONGRATES! ");
		}
	}
}