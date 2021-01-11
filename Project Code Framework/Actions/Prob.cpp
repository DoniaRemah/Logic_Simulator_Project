#include "Prob.h"
#include "..\ApplicationManager.h"
Probing::Probing(ApplicationManager* pApp) :Action(pApp)
{
	x = 0; y = 0;
}


bool Probing::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMsg("Probing...Click on Connection or Pin.");
	pIn->GetPointClicked(x, y);

	if (!pOut->IsDrawingArea(x, y)) {
		pOut->PrintMsg("Invalid position. Operation was cancelled");
		return false;
	}
	if (pManager->selectcomponent(x, y))
	{
		return true;
	}
	else
	{
		pOut->PrintMsg("Invalid Position. Operation was Cancelled.");
		return false;
	}
}

void Probing::Execute()
{
	bool status=false;
	bool ValidParameters=ReadActionParameters();
	if (ValidParameters)
	{
		Output* pOut = pManager->GetOutput();
		bool Valid = pManager->ProbingCircuit(x, y, status);
		if (Valid == false)
		{
			pOut->PrintMsg("Invalid Click. Operation Cancelled.");
		}
		else if (Valid == true && status == true)
		{
			pOut->PrintMsg("Status is 1.");
		}
		else if (Valid == true && status == false)
		{
			pOut->PrintMsg("Status is 0.");
		}
	}
	
}

void Probing::Undo()
{}

void Probing::Redo()
{}

