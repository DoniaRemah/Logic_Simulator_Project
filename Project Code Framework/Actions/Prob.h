#pragma once
#include "Action.h"
class Probing : public Action
{
	int x, y;
public:
	Probing(ApplicationManager* pApp);
	virtual bool ReadActionParameters();
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();
};