#include "SWITCH.h"

SWITCH::SWITCH(const GraphicsInfo& r_GfxInfo, int r_FanOut): m_OutputPin(r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
	IsSelected = false;
	Id = 0;

	// Associate Output Pin with Swicth
	m_OutputPin.setComponent(this);
}


void SWITCH::Operate()
{


}


// Function Draw
// Draws 2-input AND gate
void SWITCH::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawSWITCH(m_GfxInfo, IsSelected);
}

//returns status of outputpin
int SWITCH::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int SWITCH::GetInputPinStatus(int n)
{
	return -1;
}

//Set status of an input pin ot HIGH or LOW
void SWITCH::setInputPinStatus(int n, STATUS s)
{
	
}

OutputPin* SWITCH ::GetOutputPin()
{
	return &m_OutputPin;
}

SWITCH :: ~SWITCH()
{

}

int SWITCH::GetNoInputPins()
{
	return 0;
}
void SWITCH::SetIsSelected(bool select) {
	IsSelected = select;
}

bool SWITCH::GetIsSelected() {
	return IsSelected;
}
void SWITCH::Save(ofstream& Output)
{
	Output << "SWITCH" << "  " << Id << " " << GetLabel() << " "; //Printing switch info to text file
	Output << m_GfxInfo.x1 << "  " << m_GfxInfo.y1;
	Output << endl;
}
void SWITCH::SetID(int ID) {
	Id = ID;
}
int SWITCH::GetID() {
	return Id;
}
bool SWITCH::CheckIfOutpin(int& x, int& y)
{
	int xOut = m_GfxInfo.x1 + UI.AND2_Width - 5;
	int yOut = m_GfxInfo.y1 + 23;
	int diffx = x - xOut;
	if (diffx < 0) diffx = -diffx;
	int diffy = y - yOut;
	if (diffx < 0) diffy = -diffy;
	if (diffx < 5 && diffy < 5)
	{
		x = xOut;
		y = yOut;
		return true;
	}
	return false;
}