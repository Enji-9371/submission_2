#include "UnHide.h"
#include "../controller.h"

UnHide::UnHide(controller* pCont) :operation(pCont) {}
UnHide::~UnHide() {}

void UnHide::Execute() {

	GUI* pUI = pControl->GetUI();
	Graph* pGr = pControl->getGraph();

	pGr->Unhide_shapes(pUI);
}