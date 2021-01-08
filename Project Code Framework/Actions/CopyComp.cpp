#include"CopyComp.h"
#include "..\ApplicationManager.h"

Copy::Copy(ApplicationManager* pApp) :Action(pApp)
{

}

bool Copy::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMsg("PLEASE SELECT A COMPONENT TO COPY.");
	pIn->GetPointClicked(Cx, Cy);
	if (!pOut->IsDrawingArea(Cx, Cy))
	{
		pOut->PrintMsg("Invalid Area. Operation Cancelled.");
		return false;
	}
	else
	{

		if (pManager->selectcomponent(Cx, Cy))
		{
			pOut->PrintMsg("Component COPPIED. Please Click on Paste Icon.");
			return true;
		}
		else
		{
			pOut->PrintMsg("Invalid Position. Did Not Click on Component. Operation Cancelled.");
			return false;
		}
	}
}

void Copy::Execute()
{
	bool ValidParameters = ReadActionParameters();
	if (ValidParameters)
	{
		mComp = pManager->GetComponent(Cx, Cy);
		pManager->CopyComponent(mComp);
	}
}

void Copy::Undo()
{

}

void Copy::Redo()
{

}

Copy :: ~Copy()
{

}