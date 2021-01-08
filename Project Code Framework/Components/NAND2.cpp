#include "NAND2.h"

NAND2::NAND2(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(2, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}
NAND2::NAND2(int r_FanOut) :Gate(2, r_FanOut)
{

}

void NAND2::Operate()
{
	//caclulate the output status as the ANDing of the two input pins

	int inpstatus1 = GetInputPinStatus(1);
	int inpstatus2 = GetInputPinStatus(2);

	if (inpstatus1 == 1 && inpstatus2 == 1)
	{
		m_OutputPin.setStatus(LOW);
	}
	else
	{
		m_OutputPin.setStatus(HIGH);
	}

}


// Function Draw
// Draws 2-input AND gate
void NAND2::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawNAND2(m_GfxInfo, IsSelected);
	pOut->DrawString(m_GfxInfo.x1, m_GfxInfo.y1 - 20, GetLabel());
}

//returns status of outputpin
int NAND2::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int NAND2::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void NAND2::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}
void NAND2::Save(ofstream& Output)
{
	if (GetLabel() == "")
	{
		Output << "NAND2" << "  " << Id << " " << "$" << " "; //Printing the gate's info based on the file format
		Output << m_GfxInfo.x1 << "  " << m_GfxInfo.y1;
		Output << endl;      //Id is an integer defined in Gate class 
	}
	else {
		Output << "NAND2" << "  " << Id << " " << GetLabel() << " ";
		Output << m_GfxInfo.x1 << "  " << m_GfxInfo.y1;
		Output << endl;
	}
}
void NAND2::GetinputPinCoordinates(int pinNum, int& x, int& y)
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
 InputPin* NAND2::GetInPin(int n) { return m_InputPins + n - 1; }
 OutputPin* NAND2::GetOutPin() { return &m_OutputPin; }