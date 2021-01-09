#pragma once
#include "component.h"
#include "InputPin.h"
#include "OutputPin.h"

class Connection :	public Component
{
	Component*	SrcCmpnt;	//Connection source component
	Component*	DstCmpnt;	//Connection Destination component
	int		DstPinNumber;		//The Input pin to which this connection is linked
	OutputPin* SrcPin;	//The Source pin of this connection (an output pin of certain Component)
	InputPin* DstPin;	//The Destination pin of this connection (an input pin of certain Component)
	bool IsSelected;
	GraphicsInfo Broken;
public:
	//Connection(const GraphicsInfo &r_GfxInfo, Component *pS=NULL,Component *pD=NULL, int Pin=0);
	Connection(const GraphicsInfo &r_GfxInfo, GraphicsInfo& broken, OutputPin *pSrcPin,InputPin *pDstPin, Component* Src, Component* Dst);
	virtual bool InsideArea(int x,int y);
	virtual void Operate() ;	//Calculates the output according to the inputs
	virtual void Draw(Output* pOut);	//for each component to Draw itself
	void setSourcePin(OutputPin *pSrcPin);
	void setDestPin(InputPin *pDstPin);
	OutputPin* getSourcePin();
	InputPin* getDestPin();
	int GetNoInputPins();
	int GetOutPinStatus();	//returns status of outputpin if LED, return -1
    int GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1
	Component* GetSourceComponent();
	Component* GetDstComponent();
	void SetDstPinNumber(int N);
	int GetDstPinNumber();
	virtual void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.
	void SetIsSelected(bool select);
	bool GetIsSelected();
	void Save(ofstream& Outputfile);
	virtual int GetID();
	virtual void SetID(int ID);
	
	


};
