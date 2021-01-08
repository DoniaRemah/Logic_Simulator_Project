#include "XNOR2.h"

XNOR2::XNOR2(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(2, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}
XNOR2::XNOR2( int r_FanOut) :Gate(2, r_FanOut)
{

}

void XNOR2::Operate()
{
	//caclulate the output status as the ANDing of the two input pins

	//Add you code here
}


// Function Draw
// Draws 2-input AND gate
void XNOR2::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawXNOR2(m_GfxInfo, IsSelected);
	pOut->DrawString(m_GfxInfo.x1, m_GfxInfo.y1 - 20, GetLabel());
}

//returns status of outputpin
int XNOR2::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int XNOR2::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void XNOR2::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}
void XNOR2::Save(ofstream& Output)
{
	if (GetLabel() == "")
	{
		Output << "XNOR2" << "  " << Id << " " << "$" << " "; //Printing the gate's info based on the file format
		Output << m_GfxInfo.x1 << "  " << m_GfxInfo.y1;
		Output << endl;      //Id is an integer defined in Gate class 
	}
	else {
		Output << "XNOR2" << "  " << Id << " " << GetLabel() << " ";
		Output << m_GfxInfo.x1 << "  " << m_GfxInfo.y1;
		Output << endl;
	}
}
void XNOR2::GetinputPinCoordinates(int pinNum, int& x, int& y) //Divided into 3 parts and height =50
{
	if (pinNum == 1)
	{
		x = m_GfxInfo.x1;
		y = m_GfxInfo.y1 + 16;
	}
	if (pinNum == 2)
	{
		x = m_GfxInfo.x1;
		y = m_GfxInfo.y1 + 32;
	}
}
 InputPin* XNOR2::GetInPin(int n) { return m_InputPins + n - 1; }
 OutputPin* XNOR2::GetOutPin() { return &m_OutputPin; }