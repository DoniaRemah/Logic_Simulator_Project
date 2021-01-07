#pragma once
#include"Action.h"
#include"..\ApplicationManager.h"
#include"..\Components\Connection.h"
#include "..\Components\Gate.h"
#include "..\Components\LED.h"
#include "..\Components\SWITCH.h"
class Delete : public Action 
{
private:
	Component* mComp;
	int Cx, Cy;

public:
	Delete(ApplicationManager* pApp);
	virtual bool ReadActionParameters();

	//Execute action (code depends on action type)
	virtual void Execute();

	//To undo this action (code depends on action type)
	virtual void Undo();

	//To redo this action (code depends on action type)
	virtual void Redo();
};
