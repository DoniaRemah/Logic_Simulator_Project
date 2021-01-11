#include "ValidateCircuit.h"
#include "..\ApplicationManager.h"
Validate::Validate(ApplicationManager* pApp) :Action(pApp)
{

}

bool Validate::ReadActionParameters()
{
	return true;
}

void Validate::Execute()
{
	Output* pOut = pManager->GetOutput();
	bool ValidCircuit = pManager->ValidateCircuit();
	if (ValidCircuit)
	{
		pOut->PrintMsg("Circuit is VALID. You can Simulate SUCCESSFULLY.");
	}
	else
	{
		pOut->PrintMsg("Circuit is INVALID. NOT ALL PINS ARE CONNECTED.");
	}

}

void Validate::Undo()
{}

void Validate::Redo()
{}

Validate :: ~Validate()
{

}