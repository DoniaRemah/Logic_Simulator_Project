#include "Connection.h"

Connection::Connection(const GraphicsInfo &r_GfxInfo, GraphicsInfo& broken,OutputPin *pSrcPin,InputPin *pDstPin,Component* Src, Component* Dst):Component(r_GfxInfo)
	
{
	Broken = broken;
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
	pOut->DrawConnection(m_GfxInfo,Broken,IsSelected);
	pOut->DrawString(m_GfxInfo.x1, m_GfxInfo.y1 - 20, GetLabel());
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

Component* Connection :: GetSourceComponent()
{
	return SrcCmpnt;
}
Component* Connection ::GetDstComponent()
{
	return DstCmpnt;
}
void Connection::SetDstPinNumber(int N)
{
	DstPinNumber = N;
}
int Connection::GetDstPinNumber() 
{
	return DstPinNumber;
}
void Connection::GetinputPinCoordinates(int pinNum, int& x, int& y)
{

}

void Connection::SetIsSelected(bool select) {
	IsSelected = select;
}

bool Connection::GetIsSelected() {
	return IsSelected;
}
void Connection::Save(ofstream & Outputfile)
{
	int ID1 = SrcPin->GetCompID(); //OutputPin Class 
	int ID2 = DstPin->GetCompID(); //InputPin Class (According to file format: destination Component 1st and source Component 2nd)
	Outputfile << ID1 << " " << ID2 << " ";
	Outputfile << DstPinNumber << endl; //Which pin number is the connection linked to?

}
int Connection::GetID() 
{
	return -1; 
}

void Connection::SetID(int ID)
{

}

void Connection::Load(ifstream& Inputfile)
{

}
InputPin* Connection::GetInPin(int n) { return getDestPin(); }
 OutputPin* Connection::GetOutPin() { return getSourcePin(); }


bool Connection ::InsideArea(int x, int y)
{
	if (x > m_GfxInfo.x1 && x < Broken.x1 && (y > m_GfxInfo.y1 - 1.5 && y < m_GfxInfo.y1 + 1.5))
		return true;
	else if (x > Broken.x1 && x < m_GfxInfo.x2 && (y > m_GfxInfo.y2 - 1.5 && y < m_GfxInfo.y2 + 1.5))
		return true;
	else if (x == Broken.x1 && (y < m_GfxInfo.y1 && y>m_GfxInfo.y2))
		return true;
	else if (x == Broken.x1 && (y < m_GfxInfo.y1 && y > Broken.y1))
		return true;
	else if (x<Broken.x1 && x> Broken.x2 && (y > Broken.y1 - 1.5 && y < Broken.y1 + 1.5))
		return true;
	else if (x == Broken.x2 && (y < Broken.y1 && y > m_GfxInfo.y2))
		return true;
	else if (x == Broken.x1 && (y > m_GfxInfo.y1 && y < Broken.y1))
		return true;
	else if (x > Broken.x2 && x < m_GfxInfo.x2 && (y > Broken.y1 - 1.5 && y < Broken.y1 + 1.5))
		return true;
	else if (x == Broken.x2 && (y > Broken.y1 && y < m_GfxInfo.y2))
		return true;
	else if (x > m_GfxInfo.x1 && x < m_GfxInfo.x2 && (y > Broken.y1 - 1.5 && y < Broken.y1 + 1.5))
		return true;
	else
		return false;
}
