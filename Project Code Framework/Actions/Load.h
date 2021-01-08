#pragma once
#include "action.h"
#include "..\Components\Component.h"

class Loading : public Action
{
private:
	//Parameters for rectangular area to be occupied by the gate
	int Cx, Cy;	//Center point of the gate
	int x1, y1, x2, y2;	//Two corners of the rectangluar area
	ifstream Inputfile;
public:
	Loading(ApplicationManager* pApp);
	virtual ~Loading(void);

	//Reads parameters required for action to execute
	virtual bool ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};