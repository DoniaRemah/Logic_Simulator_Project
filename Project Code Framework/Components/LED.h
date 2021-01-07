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
	InputPin m_InputPin;
	bool IsSelected;
	int Id;
public:
	LED(const GraphicsInfo& r_GfxInfo);
	virtual void Operate();	//Calculates the output of LED 
	virtual void Draw(Output* pOut);	//Draws LED
	virtual int GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1
	virtual int GetOutPinStatus();
	virtual void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.
	InputPin* GetInputPin();
	virtual int GetNoInputPins();
	void SetIsSelected(bool select);
	bool GetIsSelected();
	virtual void Save(ofstream& Output); //Function for save 
	void SetID(int ID);
	int GetID();
	bool CheckIfOutpin(int& x, int& y);
	bool CheckIfInpin(int& x, int& y, int& inputnum);
	void UnConnectInputPin();
	virtual ~LED();

};

#endif

