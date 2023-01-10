#include "Hide.h"
#include "../controller.h"

Hide::Hide(controller* pCont) :operation(pCont) {}
Hide::~Hide() {}

void Hide::Execute() {

	GUI* pUI = pControl->GetUI();
	Graph* pGr = pControl->getGraph();

	pGr->Hide_shapes(pUI);
}