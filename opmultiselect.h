#pragma once
#include "operations/operation.h"

class  MULTISELECT : public operation
{
private:
    int* multiSelect;
public:
    MULTISELECT(controller* pApp, int& _multiSelect);
    virtual void Execute();
};
