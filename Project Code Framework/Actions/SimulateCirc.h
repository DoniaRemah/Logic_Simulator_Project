#ifndef  _SIMULATE_CIRC_H
#define  _SIMULATE_CIRC_H


#pragma once
#include "Action.h"


class Simulate : public Action
{
private:

public:

	Simulate(ApplicationManager* pApp);
	//Reads parameters required for action to execute
	virtual bool ReadActionParameters();

	//Execute action (code depends on action type)
	virtual void Execute();

	//To undo this action (code depends on action type)
	virtual void Undo();

	//To redo this action (code depends on action type)
	virtual void Redo();
	~Simulate();
};


#endif 
