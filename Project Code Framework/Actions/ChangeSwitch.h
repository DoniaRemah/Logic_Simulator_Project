#pragma once

#include "Action.h"
#include "..\Components\SWITCH.h"

class ChangeSwitch : public Action
{
	int Cx; int Cy;

public:

	ChangeSwitch(ApplicationManager* pApp);
	virtual bool ReadActionParameters();

	virtual void Execute();

	virtual void Undo();

	virtual void Redo();
	void SetParameters(int x);
	~ChangeSwitch();
};