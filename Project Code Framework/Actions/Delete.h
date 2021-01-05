#pragma once
#include"Action.h"
#include"..\ApplicationManager.h"
#include"..\Components\Connection.h"

class Delete : public Action 
{
private:
	Component* mComp;
	int Cx, Cy;
	ApplicationManager* pApp;
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
