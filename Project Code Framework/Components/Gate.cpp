#include "Gate.h"

//Gate Constructor
//Parameters:
//r_Inputs: no. of gate's input pins
//r_FanOut: Fan out of the gate's output pin
Gate::Gate(int r_Inputs, int r_FanOut):m_OutputPin(r_FanOut)
{
	count++;
	//Allocate number of input pins (equals r_Inputs)
	m_InputPins = new InputPin[r_Inputs];
	m_Inputs = r_Inputs;	//set no. of inputs of that gate
	
	//Associate all input pins to this gate +SETTING ID
	for (int i = 0; i < m_Inputs; i++)
		m_InputPins[i].setComponent(this);
	
	

	//Associate Output pin to this gate 
	m_OutputPin.setComponent(this);
	

	IsSelected = false; //Initially a component is not selected
	
}

InputPin* Gate::GetInputPin(int N)
{
	return &m_InputPins[N-1];
}

OutputPin* Gate::GetOutputPin()
{
	return &m_OutputPin;
}



int Gate::GetNoInputPins()
{
	return m_Inputs;
}


void Gate::SetIsSelected(bool select) {
	IsSelected = select;
}

bool Gate::GetIsSelected() {
	return IsSelected;
}
int Gate::GetID() 
{
	return Id;
}

void Gate::SetID(int ID)
{
	Id = ID;
}


void Gate::UnConnectInputPin(int N)
{
	m_InputPins[N-1].unConnect();
}
void Gate::UnConnectOuputPin(Connection* Conn)
{
	m_OutputPin.unConnect(Conn);
}
void Gate::Load(ifstream& Inputfile)
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