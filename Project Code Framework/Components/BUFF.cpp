#include "BUFF.h"

BUFF::BUFF(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(1, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


void BUFF::Operate()
{
	//caclulate the output status as the ANDing of the two input pins

	int inpstatus1 = GetInputPinStatus(1);
	if (inpstatus1==1)
		m_OutputPin.setStatus(HIGH);
	else
		m_OutputPin.setStatus(LOW);

}


// Function Draw
// Draws 1-input BUFF gate
void BUFF::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawBUFFER(m_GfxInfo, IsSelected);
	pOut->DrawString(m_GfxInfo.x1, m_GfxInfo.y1 - 20, GetLabel());
}

//returns status of outputpin
int BUFF::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int BUFF::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void BUFF::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}

void BUFF::Save(ofstream& Output)
{
	if (GetLabel() == "")
	{
		Output << "BUFF" << "  " << Id << " " << "$" << " "; //Printing the gate's info based on the file format
		Output << m_GfxInfo.x1 << "  " << m_GfxInfo.y1;
		Output << endl;      //Id is an integer defined in Gate class 
	}
	else {
		Output << "BUFF" << "  " << Id << " " << GetLabel() << " ";
		Output << m_GfxInfo.x1 << "  " << m_GfxInfo.y1;
		Output << endl;
	}
}

