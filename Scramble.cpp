#include "Scramble.h"
#include "controller.h"
#include "GUI\GUI.h"
#include "Shapes/Graph.h"


opScramble::opScramble(controller* pCont) :operation(pCont)
{}

opScramble::~opScramble() = default;

void opScramble::Execute()
{

	/// Grid Points
	/* (200,150) (400, 150) (600, 150) (800, 150) (1000, 150) (1200, 150)
		(200,300) (400, 300) (600, 300) (800, 300) (1000, 300) (1200, 300)
		(200,450) (400, 450) (600, 450) (800, 450) (1000, 450) (1200, 450)
		(200,450) (400, 450) (600, 450) (800, 450) (1000, 450) (1200, 450)
	*/

	GUI* pUI = pControl->GetUI();
	Graph* pGr = pControl->getGraph();
	pGr->Scramble();
	pUI->PrintMessage("Shapes are Scrambled");
	pUI->ClearStatusBar();

}
void opScramble::Undo() {}
void opScramble::Redo() {}