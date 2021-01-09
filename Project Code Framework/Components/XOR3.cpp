#include "XOR3.h"
XOR3::XOR3(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(3, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}
XOR3::XOR3( int r_FanOut) :Gate(3, r_FanOut)
{

}

void XOR3::Operate()
{
	int inpstatus1 = GetInputPinStatus(1);
	int inpstatus2 = GetInputPinStatus(2);
	int inpstatus3 = GetInputPinStatus(3);

	if ((inpstatus1 + inpstatus2 + inpstatus3) == 1 || (inpstatus1 + inpstatus2 + inpstatus3) == 3)
	{
		m_OutputPin.setStatus(HIGH);
	}
	else
	{
		m_OutputPin.setStatus(LOW);
	}
}


// Function Draw
// Draws 3-input XOR gate
void XOR3::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawXOR3(m_GfxInfo, IsSelected);
	pOut->DrawString(m_GfxInfo.x1, m_GfxInfo.y1 - 20, GetLabel());
}

//returns status of outputpin
int XOR3::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int XOR3::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void XOR3::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}

void XOR3::Save(ofstream& Output)
{
	if (GetLabel() == "")
	{
		Output << "XOR3" << "  " << Id << " " << "$" << " "; //Printing the gate's info based on the file format
		Output << m_GfxInfo.x1 << "  " << m_GfxInfo.y1;
		Output << endl;      //Id is an integer defined in Gate class 
	}
	else {
		Output << "XOR3" << "  " << Id << " " << GetLabel() << " ";
		Output << m_GfxInfo.x1 << "  " << m_GfxInfo.y1;
		Output << endl;
	}
}
void XOR3::GetinputPinCoordinates(int pinNum, int& x, int& y) //Divided into 4 parts 
{
	if (pinNum == 1)
	{
		x = m_GfxInfo.x1;
		y = m_GfxInfo.y1 + 12;
	}
	if (pinNum == 2)
	{
		x = m_GfxInfo.x1;
		y = m_GfxInfo.y1 + 24;
	}
	if (pinNum == 3)
	{
		x = m_GfxInfo.x1;
		y = m_GfxInfo.y1 + 36;
	}
}
 InputPin* XOR3::GetInPin(int n) { return m_InputPins + n - 1; }
 OutputPin* XOR3::GetOutPin() { return &m_OutputPin; }