#pragma once
#ifndef _ADD_CONNECTION_H
#define _ADD_CONNECTION_H
#endif

#include "Action.h"
#include "..\Components\Connection.h"

class AddConnection :public Action
{
	int x1, y1, x2, y2;
	Component* m_SrcComp;
	Component* m_DstComp;
public:
	AddConnection(ApplicationManager* pApp);
	virtual ~AddConnection(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
};