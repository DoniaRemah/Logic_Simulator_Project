#include "LED.h"

LED::LED(const GraphicsInfo& r_GfxInfo)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;

	// Associate Input pin with Led.
	
	m_InputPin.setComponent(this);
}


void LED::Operate()
{
	int inpstatus = GetInputPinStatus(1);


}


// Function Draw
// Draws 2-input AND gate
void LED::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawBULB(m_GfxInfo);
	pOut->DrawString(m_GfxInfo.x1, m_GfxInfo.y1 - 20, GetLabel());
}



//returns status of Inputpin #n
int LED::GetInputPinStatus(int n)
{
	return m_InputPin.getStatus();	
}

int  LED::GetOutPinStatus()
{
	return -1;
}

//Set status of an input pin ot HIGH or LOW
void LED::setInputPinStatus(int n, STATUS s)
{
	m_InputPin.setStatus(s);
}

LED :: ~LED()
{

}

InputPin* LED ::GetInputPin()
{
	return &m_InputPin;
}

int LED::GetNoInputPins()
{
	return 1;
}

void LED::UnConnectInputPin()
{
	m_InputPin.unConnect();
}
