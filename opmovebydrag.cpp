#include "opmovebydrag.h"
#include "controller.h"
#include "GUI/GUI.h"

Move::Move(controller* pCont) :operation(pCont)
{}
Move::~Move()
{}

//Execute the operation
void Move::Execute()
{
    GUI* pUI = pControl->GetUI();
    Point P;
  
    Graph* pGr = pControl->getGraph();
    window* pWind = pUI->DetectMouse();
    GUI* pIn = pControl->GetUI();
    pIn->PrintMessage(" MOVE IS ON SELECT A SHAPE..  ");

    while (pWind->GetButtonState(LEFT_BUTTON, P.x, P.y) != BUTTON_DOWN)
    {
        if (pGr->Getshape(P.x, P.y) != nullptr)
        {
            shape* Selected_shape = pGr->Getshape(P.x, P.y);
            Selected_shape->Move(P);
            pUI->ClearDrawArea();
            pControl->UpdateInterface();
            Sleep(40);

        }

    }

}


void Move::Undo()
{
    Graph* pGr = pControl->getGraph();
    pGr->AddToUndoStack();
}
void Move::Redo()
{
    Graph* pGr = pControl->getGraph();
    pGr->AddtoShapeList();
}












