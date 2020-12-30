#pragma once
#include "Actions/Action.h"
#include "Components/Pin.h"
class DrawConnection : public Action
{
private:
	Pin* OutputPin;
	Pin* InputPin;

public:
	DrawConnection(ApplicationManager* pApp);
	virtual ~DrawConnection(void);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();

};