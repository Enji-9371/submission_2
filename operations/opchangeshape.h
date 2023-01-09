#pragma once
#include "operation.h"
#include "..\GUI\GUI.h"

//Add color palette operation class
class opClrPlt : public operation
{
public:
	operationType return_CreateColorBar;
	opClrPlt(controller* pCont);
	virtual ~opClrPlt();

	//Add color palette to the controller
	virtual void Execute();

};



//Add pen width operation class
class opPenWidth : public operation
{
public:
	string wchoice; //string to save the input
	opPenWidth(controller* pCont);
	virtual ~opPenWidth();

	//Add changing pen width order to the controller
	virtual void Execute();

};



//Add changes on singl shape operation class
class opChngSelInfo : public operation
{
public:
	opChngSelInfo(controller* pCont);
	virtual ~opChngSelInfo();

	//Add color palette to the controller
	virtual void Execute();

};