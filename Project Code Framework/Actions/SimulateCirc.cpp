#include "SimulateCirc.h"
#include "..\ApplicationManager.h"

Simulate::Simulate(ApplicationManager* pApp):Action(pApp)
{

}

bool Simulate::ReadActionParameters()
{
	return true;
}

void Simulate::Execute()
{
	pManager->SimulateCircuit(); 
}

void Simulate::Undo()
{}

void Simulate::Redo()
{}

Simulate :: ~Simulate()
{

}

