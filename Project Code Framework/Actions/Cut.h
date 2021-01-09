#ifndef _Cut_Comp_H 
#define _Cut_Comp_H 

#pragma once
#include "Action.h"
#include"..\Components\Component.h"

class CutComp : public Action
{
private:
	int Cx, Cy;	
	Component* mComp;
public:
	CutComp(ApplicationManager* pApp);
	//Reads parameters required for action to execute
	virtual bool ReadActionParameters();

	//Execute action (code depends on action type)
	virtual void Execute();

	//To undo this action (code depends on action type)
	virtual void Undo();

	//To redo this action (code depends on action type)
	virtual void Redo();
	 ~CutComp();
	
};

#endif 