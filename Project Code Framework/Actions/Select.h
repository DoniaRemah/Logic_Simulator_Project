#pragma once
#include"Action.h"
#include"..\ApplicationManager.h"
#include"..\Components\Gate.h"
#include"..\Components\LED.h"
#include"..\Components\SWITCH.h"
#include"..\Components\Connection.h"

class Select : public Action {
private:
	Component* mComp;
	int Cx, Cy;
	ApplicationManager* pApp;
public:
	Select(ApplicationManager* pApp);	//constructor

	//Reads parameters required for action to execute
	virtual bool ReadActionParameters();

	//Execute action (code depends on action type)
	virtual void Execute();

	//To undo this action (code depends on action type)
	virtual void Undo();

	//To redo this action (code depends on action type)
	virtual void Redo();
	virtual ~Select(void);

};
