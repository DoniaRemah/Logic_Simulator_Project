#include "AND3.h"

AND3::AND3(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(3, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


void AND3::Operate()
{
	//caclulate the output status as the ANDing of the two input pins

	int inpstatus1 = GetInputPinStatus(1);
	int inpstatus2 = GetInputPinStatus(2);
	int inpstatus3 = GetInputPinStatus(3);

	if (inpstatus1 == 1 && inpstatus2 == 1 && inpstatus3==1)
	{
		m_OutputPin.setStatus(HIGH);
	}
	else
	{
		m_OutputPin.setStatus(LOW);
	}

}


// Function Draw
// Draws 3-input AND gate
void AND3::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawString(m_GfxInfo.x1, m_GfxInfo.y1 - 20, GetLabel());
	pOut->DrawAND3(m_GfxInfo, IsSelected);
}

//returns status of outputpin
int AND3::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int AND3::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void AND3::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}

void AND3::Save(ofstream & Output)
{
	if (GetLabel() == "")
	{
		Output << "AND3" << "  " << Id << " " << "$" << " "; //Printing the gate's info based on the file format
		Output << m_GfxInfo.x1 << "  " << m_GfxInfo.y1;
		Output << endl;      //Id is an integer defined in Gate class 
	}
	else {
		Output << "AND3" << "  " << Id << " " << GetLabel() << " ";
		Output << m_GfxInfo.x1 << "  " << m_GfxInfo.y1;
		Output << endl;
	}
}
