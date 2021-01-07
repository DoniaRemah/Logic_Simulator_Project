#ifndef _GATE_H
#define _GATE_H

/*
  Class Gate
  -----------
  - Base class for all types of gates
  - Each gate has n inputs pins and one output pin
*/


#include "InputPin.h"
#include "OutputPin.h"
#include "Component.h"
#include "Connection.h"

class Gate:public Component
{
protected:
	InputPin* m_InputPins;	//Array of input pins of the Gate
	OutputPin m_OutputPin;	//The Gate output pin
	int m_Inputs;		//No. of input pins of that Gate.
	bool IsSelected;
	int Id;
public:
	Gate(int r_Inputs, int r_FanOut);
	InputPin* GetInputPin(int N);
	OutputPin* GetOutputPin();
	void UnConnectInputPin(int N);
	void UnConnectOuputPin(Connection* Conn);
	virtual int GetNoInputPins();
	void SetIsSelected(bool select);
	bool GetIsSelected();
	virtual void SetID(int ID);
	virtual int GetID();
	void Save(ofstream& OutPut) = 0; //Pure function to be overridden by all gates

	
};

#endif
