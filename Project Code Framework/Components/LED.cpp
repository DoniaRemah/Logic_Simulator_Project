#include "LED.h"

LED::LED(const GraphicsInfo& r_GfxInfo)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
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
}



//returns status of Inputpin #n
int LED::GetInputPinStatus(int n)
{
	n = 1;
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

int  LED::GetOutPinStatus()
{
	return -1;
}

//Set status of an input pin ot HIGH or LOW
void LED::setInputPinStatus(int n, STATUS s)
{
	
}

LED :: ~LED()
{

}

