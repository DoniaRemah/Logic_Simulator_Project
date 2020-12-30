#ifndef _LED_H
#define _LED_H

/*
  Class LED
  -----------
  represent the LED
*/
#include "Component.h"
#include "InputPin.h"
class LED :public Component
{
protected :
	InputPin* m_InputPins;
public:
	LED(const GraphicsInfo& r_GfxInfo);
	virtual void Operate();	//Calculates the output of LED 
	virtual void Draw(Output* pOut);	//Draws LED

	virtual int GetInputPinStatus();	//returns status of Inputpin # n if SWITCH, return -1
	virtual int GetOutPinStatus();
	virtual void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.


};

#endif

