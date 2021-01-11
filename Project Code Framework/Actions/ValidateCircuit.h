#ifndef _Validate_Circuit_H
#define _Validate_Circuit_H


#pragma once
#include "Action.h"

class Validate :public Action
{
public:
	Validate(ApplicationManager* pApp);

	virtual bool ReadActionParameters();

	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
	~Validate();
};


#endif