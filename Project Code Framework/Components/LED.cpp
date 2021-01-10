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
LED::LED(int r_FanOut)
{
	m_InputPin.setComponent(this);
	IsSelected = false;
}

void LED::Operate()
{
	
}


// Function Draw
// Draws 2-input AND gate
void LED::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	if (GetInputPinStatus(1) == LOW)
	{
		pOut->DrawBULB(m_GfxInfo, IsSelected);
	}
	else
	{
		pOut->DrawBULB(m_GfxInfo, IsSelected,true);
	}

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
	if (GetLabel() == "")
	{
		Output << "LED" << "  " << Id << " " << "$" << " "; //Printing the gate's info based on the file format
		Output << m_GfxInfo.x1 << "  " << m_GfxInfo.y1;
		Output << endl;      //Id is an integer defined in Gate class 
	}
	else {
		Output << "LED" << "  " << Id << " " << GetLabel() << " ";
		Output << m_GfxInfo.x1 << "  " << m_GfxInfo.y1;
		Output << endl;
	}
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

void LED::UnConnectInputPin()
{
	m_InputPin.unConnect();
}
void LED::GetinputPinCoordinates(int inputnum, int& x, int& y)
{
	if (inputnum == 1)
	{
		x = m_GfxInfo.x1;
		y = m_GfxInfo.y1 + 24;
	}
}
void LED::Load(ifstream& Inputfile)
{
	int ID;
	string label;
	int Cx;
	int Cy;
	Inputfile >> ID;
	Inputfile >> label;
	Inputfile >> Cx;
	Inputfile >> Cy;
	m_GfxInfo.x1 = Cx - UI.AND2_Height / 2;
	m_GfxInfo.x2 = Cx + UI.AND2_Height / 2;
	m_GfxInfo.y1 = Cy - UI.AND2_Width / 2;
	m_GfxInfo.y2 = Cy + UI.AND2_Width / 2;
	SetLabel(label);
	Id = ID;
}
InputPin* LED::GetInPin(int n) { return &m_InputPin; }
OutputPin*LED:: GetOutPin() { return NULL; }