#ifndef _Copy_Comp_H
#define _Copy_Comp_H
#pragma once

#include "Action.h"
#include "..\Components\Component.h"

class Copy: public Action
{
	int Cx, Cy;
	Component* mComp;
public:
	Copy(ApplicationManager* pApp); // Constructor

	//Reads parameters required for action to execute
	virtual bool ReadActionParameters();

	//Execute action (code depends on action type)
	virtual void Execute();

	//To undo this action (code depends on action type)
	virtual void Undo();

	//To redo this action (code depends on action type)
	virtual void Redo();
	~Copy();

};



#endif