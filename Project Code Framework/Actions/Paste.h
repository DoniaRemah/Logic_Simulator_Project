#ifndef _PASTE_H
#define _PASTE_H


#pragma once
#include "Action.h"
class Paste :public Action
{
	int Cx, Cy;
public:

	Paste(ApplicationManager* pApp);

	virtual bool ReadActionParameters();

	//Execute action (code depends on action type)
	virtual void Execute();

	//To undo this action (code depends on action type)
	virtual void Undo();

	//To redo this action (code depends on action type)
	virtual void Redo();
	~Paste();
};

#endif 
