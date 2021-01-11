#include "ChangeSwitch.h"
#include "..\ApplicationManager.h"

ChangeSwitch::ChangeSwitch(ApplicationManager* pApp, int x,int y) : Action(pApp)
{
	m_x = x;
	m_y = y;
}
bool ChangeSwitch::ReadActionParameters()
{
	if (pManager->CheckSwitch(m_x, m_y))
	{
		return true;
	}
	else
	{
		return false;
	}

}



void ChangeSwitch::Execute()
{
	bool Valid = ReadActionParameters();
	if (Valid)
	{
		pManager->ChangeSwitchF();
	}
}

void ChangeSwitch::Undo()
{}

void ChangeSwitch::Redo()
{}


ChangeSwitch:: ~ChangeSwitch()
{

}
