#include "Connection.h"

Connection::Connection(const GraphicsInfo &r_GfxInfo, OutputPin *pSrcPin,InputPin *pDstPin,Component* Src, Component* Dst):Component(r_GfxInfo)
	
{
	SrcPin = pSrcPin;
	DstPin = pDstPin;
	SrcCmpnt = Src;
	DstCmpnt = Dst;
	IsSelected = false;
}
void Connection::setSourcePin(OutputPin *pSrcPin)
{	SrcPin = pSrcPin;	}

OutputPin* Connection::getSourcePin()
{	return SrcPin;	}


void Connection::setDestPin(InputPin *pDstPin)
{	DstPin = pDstPin;	}

InputPin* Connection::getDestPin()
{	return DstPin;	}


void Connection::Operate()
{
	//Status of connection destination pin = status of connection source pin
	DstPin->setStatus((STATUS)SrcPin->getStatus());
}

void Connection::Draw(Output* pOut)
{
	pOut->DrawConnection(m_GfxInfo, IsSelected);
}

int Connection::GetOutPinStatus()	//returns status of outputpin if LED, return -1
{
	return DstPin->getStatus();
}


int Connection::GetInputPinStatus(int n)	//returns status of Inputpin # n if SWITCH, return -1
{
	return SrcPin->getStatus();	//n is ignored as connection has only one input pin (src pin)	
}

void Connection::setInputPinStatus(int n, STATUS s)
{
	SrcPin->setStatus(s);
}

int Connection::GetNoInputPins()
{
	return 0;
}

void Connection::DeleteComp(Output * pOut, GraphicsInfo delgfx)
{
	pOut->DrawConnection(delgfx,false,true);
}

void Connection::SetIsSelected(bool select) {
	IsSelected = select;
}

bool Connection::GetIsSelected() {
	return IsSelected;
}
