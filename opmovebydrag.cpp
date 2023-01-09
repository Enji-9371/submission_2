#include "opmovebydrag.h"
#include "controller.h"
#include "GUI/GUI.h"

opMove::opMove(controller* pCont) :operation(pCont)
{}
opMove::~opMove()
{}

//Execute the operation
void opMove::Execute()
{
    GUI* pUI = pControl->GetUI();
    Point P;
  
    Graph* pGr = pControl->getGraph();
    window* pWind = pUI->DetectMouse();
    GUI* pIn = pControl->GetUI();
    pIn->PrintMessage(" SELCT SHAPE TO MOVE ");

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











