#ifndef _SWITCH_H
#define _SWITCH_H

/*
  Class AND2
  -----------
  represent the 2-input AND gate
*/

#include "Component.h"
#include "OutputPin.h"
#include "Connection.h"
class SWITCH :public Component
{
protected:
	OutputPin m_OutputPin;
	bool IsSelected;
public:
	SWITCH(const GraphicsInfo& r_GfxInfo, int r_FanOut);
	virtual void Operate();	//Calculates output of switch
	virtual void Draw(Output* pOut);	//Draws SWITCH
	virtual int GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1
	virtual int GetNoInputPins(); 
	void SetIsSelected(bool select);
	bool GetIsSelected();
	virtual void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.
	OutputPin* GetOutputPin(); // Gets pointet to pin
	void UnConnectOuputPin(Connection* Conn);
	virtual ~SWITCH();
};

#endif

