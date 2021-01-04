#pragma once
#ifndef _ADD_CONNECTION_H
#define _ADD_CONNECTION_H


#include "Action.h"
#include "..\Components\Connection.h"
#include"..\Components\Gate.h"
#include "..\Components\LED.h"
#include "..\Components\SWITCH.h"
class AddConnection :public Action
{
private:
	int x1, y1, x2, y2;
	Component* m_SrcComp;
	Component* m_DstComp;
	OutputPin* SrcPin;
	InputPin* DstPin;
	bool ValidParameters;
	bool IsCancelled;
	int AvailablePinNumber;
	
public:
	AddConnection(ApplicationManager* pApp);
	virtual ~AddConnection(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();
	bool CheckValidSrc(Component** CompList, int Comp_Count, bool &validOutPin, OutputPin*& pot_outpin); // Checks if user clicked on component on screen + output pin availabilty. 
	bool CheckValidDst(Component** CompList, int Comp_Count, bool &validInPin, InputPin*&pot_InputPin); // Checks if user clicked on component on screen + if input pin availability.
	virtual void Undo();
	virtual void Redo();
	
};

#endif