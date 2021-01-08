#include "ChangeSwitch.h"
#include "..\ApplicationManager.h"

ChangeSwitch::ChangeSwitch(ApplicationManager* pApp) : Action(pApp)
{

}
bool ChangeSwitch::ReadActionParameters()
{
	return false;
}

void ChangeSwitch::Undo()
{}

void ChangeSwitch::Redo()
{}


ChangeSwitch:: ~ChangeSwitch()
{

}

void ChangeSwitch::Execute()
{
	
	pManager->ChangeSwitchF();

}

