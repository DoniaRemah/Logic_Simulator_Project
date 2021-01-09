#pragma once

#include "Action.h"
#include "..\Components\SWITCH.h"

class ChangeSwitch : public Action
{
	int m_x; int m_y;

public:

	ChangeSwitch(ApplicationManager* pApp, int x, int y);

	virtual bool ReadActionParameters();

	virtual void Execute();

	virtual void Undo();

	virtual void Redo();

	~ChangeSwitch();
};