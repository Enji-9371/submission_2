#include "Exit.h"
#include "../controller.h"
#include<windows.h>
#include "../Shapes/Shape.h"
//#include "opsave.h"

Exit::Exit(controller* pCont) :operation(pCont)
{
}


Exit::~Exit(void)
{

}

void Exit::Execute()
{
	GUI* pUI = pControl->GetUI();
	pUI->PrintMessage("Do you want to save this file?");
	Write = pUI->GetSrting();
	if ((Write == "yes") || (Write == "y") || (Write == "Yes") || (Write == "Y"))
	{
		pUI->PrintMessage("Enter the file name: ");
		x = pUI->GetSrting();
		ofstream OutFile;
		OutFile.open(x + ".txt");
		pControl->getGraph() -> Graph::Save(OutFile);
		pUI->ClearDrawArea();
		Sleep(200);

		pUI->ClearStatusBar();
		Sleep(200);

		pUI->PrintMessage("Cleaning...");
		Sleep(200);

		pUI->PrintMessage("Exiting the program... The program is saved");
		Sleep(200);
		delete pUI;
	}
	else
	{
		pUI->ClearDrawArea();
		Sleep(200);

		pUI->ClearStatusBar();
		Sleep(200);

		pUI->PrintMessage("Cleaning...");
		Sleep(200);

		pUI->PrintMessage("Exiting the program... The program is saved");
		Sleep(200);
		delete pUI;
	}
}

void Exit::Undo()
{
}
void Exit::Redo()
{
}