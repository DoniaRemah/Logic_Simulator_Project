#ifndef _COMPONENT_H
#define _COMPONENT_H

#include "..\Defs.h"
#include "..\GUI\Output.h"
#include<fstream> //For save and load

//Base class for classes Gate, Switch, and LED.
class Component
{
private:
	string m_Label;
protected:
	GraphicsInfo m_GfxInfo;	//The parameters required to draw a component
	int count;
public:
	Component(const GraphicsInfo &r_GfxInfo);
	virtual void Operate() = 0;	//Calculates the output according to the inputs
	virtual void Draw(Output* pOut) = 0;	//for each component to Draw itself
	bool InsideArea(int x, int y); // Checks if point clicked is inside the area of component
	virtual int GetOutPinStatus()=0;	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n)=0;	//returns status of Inputpin # n if SWITCH, return -1
	virtual void setInputPinStatus(int n, STATUS s)=0;	//set status of Inputpin # n, to be used by connection class.
	GraphicsInfo GetGfxInfo(); // returns the 4 corners of the component
	void SetGfxInfo(const GraphicsInfo & gfx);
	virtual int GetNoInputPins()=0;
	string GetLabel();
	void SetLabel(string NewLabel);
	virtual void Save(ofstream&) = 0; //Save function (will be overridden in every component)
	virtual void SetID(int ID) = 0;
	virtual int GetID() = 0;
	Component();	
	
	
	
	//Destructor must be virtual
	virtual ~Component();
};

#endif
