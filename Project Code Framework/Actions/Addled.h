#ifndef _ADD_led_H
#define _ADD_led_H

#include "action.h"
#include "..\Components\LED.h"

class Addled : public Action
{
private:
	//Parameters for rectangular area to be occupied by the gate
	int Cx, Cy;	//Center point of the gate
	int x1, y1, x2, y2;	//Two corners of the rectangluar area
public:
	Addled(ApplicationManager* pApp);
	virtual ~Addled(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();
	virtual int GetInputPinStatus();
	virtual void Undo();
	virtual void Redo();
};

#endif

