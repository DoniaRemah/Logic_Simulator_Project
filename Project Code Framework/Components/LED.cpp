#include "LED.h"

LED::LED(const GraphicsInfo& r_GfxInfo)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
	IsSelected = false;
	Id = 0;
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
	pOut->DrawBULB(m_GfxInfo, IsSelected);
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

void LED::SetIsSelected(bool select) {
	IsSelected = select;
}

bool LED::GetIsSelected() {
	return IsSelected;
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
void LED::Save(ofstream& Output)
{
	Output << "LED" << "  " << Id << " " << GetLabel() << " "; //Printing info of LED (Like what happenned in gates)
	Output << m_GfxInfo.x1 << "  " << m_GfxInfo.y1;
	Output << endl;
}
void LED::SetID(int ID) {
	Id = ID;
}
int LED::GetID() {
	return Id;
}
bool LED::CheckIfOutpin(int& x, int& y)
{
	return false;
}
bool LED::CheckIfInpin(int& x, int& y, int& inputnum)
{
	int xIn1 = m_GfxInfo.x1;
	int yIn1 = m_GfxInfo.y1 + 24;
	int diffx = x - xIn1;
	if (diffx < 0) diffx = -diffx;
	int diffy = y - yIn1;
	if (diffy < 0) diffy = -diffy;
	if (diffx < 5 && diffy < 5)
	{
		inputnum = 1;
		x = xIn1;
		y = yIn1;
		return true;
	}
	return false;
}